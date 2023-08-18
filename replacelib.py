# =============================================================================
# MIT License
# 
# Copyright (c) 2023 luckytyphlosion
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
# =============================================================================

import re
import csv
from wcmatch import glob as wcmatch_glob
from contextlib import contextmanager
import json
import pathlib
import io
import sys
import os

def open_l(filename, mode):
    return open(filename, mode, encoding="utf-8", newline="\n")

class StringContainer:
    __slots__ = ("value", "num_replacements")

    def __init__(self, value):
        self.value = value
        self.num_replacements = 0

WORD_CHARACTERS = set("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_")

class Replacer:
    @staticmethod
    def single_replace(input, replace_from, replace_to):
        if replace_from[0] in WORD_CHARACTERS:
            pattern_start = "\\b"
        else:
            pattern_start = ""

        if replace_from[-1] in WORD_CHARACTERS:
            pattern_end = "\\b"
        else:
            pattern_end = ""

        pattern = re.compile(f"{pattern_start}{re.escape(replace_from)}{pattern_end}")

        return pattern.subn(replace_to, input)

    @staticmethod
    def create_multiple_replace_pattern(rep_dict):
        sorted_rep_dict_values = sorted(rep_dict, key=len, reverse=True)
        pattern_parts = []
        for replace_from in sorted_rep_dict_values:
            if replace_from[0] in WORD_CHARACTERS:
                pattern_start = "\\b"
            else:
                pattern_start = ""

            if replace_from[-1] in WORD_CHARACTERS:
                pattern_end = "\\b"
            else:
                pattern_end = ""

            pattern_parts.append(f"{pattern_start}{re.escape(replace_from)}{pattern_end}")

        pattern_str = "|".join(pattern_parts)

        pattern = re.compile(pattern_str, flags=re.DOTALL)
        print(f"multiple_replace pattern_str: {pattern_str}")
        return pattern

    @staticmethod
    def multiple_replace(input, pattern, rep_dict):
        if len(rep_dict) == 0:
            return input, 0

        def multiple_replace_lambda(x):
            return rep_dict[x.group(0)]

        return pattern.subn(multiple_replace_lambda, input)

    @contextmanager
    @staticmethod
    def open_and_write(filename):
        file_obj = open_l(filename, "r+")
        string_container = StringContainer(file_obj.read())
        try:
            yield string_container
        except Exception as e:
            file_obj.close()
            raise e
        finally:
            if string_container.num_replacements != 0:
                file_obj.truncate(size=0)
                file_obj.write(string_container.value)
            file_obj.close()

    @staticmethod
    def single_replace_for_file(filename, replace_from, replace_to):
        with open_and_write(filename) as string_container:
            string_container.value, string_container.num_replacements = Replacer.single_replace(string_container.value, replace_from, replace_to)

    @staticmethod
    def single_replace_for_file_result_only(filename, replace_from, replace_to):
        try:
            with open_l(filename, "r") as f:
                contents = f.read()
        except UnicodeDecodeError as e:
            raise RuntimeError(f"filename: {filename}") from e

        return Replacer.single_replace(contents, replace_from, replace_to)

    @staticmethod
    def multiple_replace_for_file(filename, pattern, rep_dict):
        with open_and_write(filename) as string_container:
            string_container.value, string_container.num_replacements = Replacer.multiple_replace(string_container.value, pattern, rep_dict)

    @staticmethod
    def multiple_replace_for_file_result_only(filename, pattern, rep_dict):
        with open_l(filename, "r") as f:
            contents = f.read()

        return Replacer.multiple_replace(contents, pattern, rep_dict)

class Replacement:
    __slots__ = ("replace_from", "replace_to")

    def __init__(self, replace_from, replace_to):
        self.replace_from = replace_from
        self.replace_to = replace_to

class ReplacementData:

    @staticmethod
    def read_in(replacements_filename):
        pathlib.Path(replacements_filename).touch()

        with open_l(replacements_filename, "r") as f:
            replacements_reader = csv.reader(f)
            data = [x for x in list(replacements_reader) if len(x) != 0]

        return data

    @staticmethod
    # main logic was mostly generated by GPT-4 wtf
    def validate_and_resolve(replacements_data, print_errors=True, throw_error=False, throw_error_message_prefix=None):
        resolved_replacements_data_dict = {}
        errors = False

        for parent, child in replacements_data:
            for node, p_child in list(resolved_replacements_data_dict.items()):
                if p_child == parent:
                    parent = node
                    del resolved_replacements_data_dict[node]
                    break
    
            node_already_in_graph = False
    
            for cur_parent, cur_child in resolved_replacements_data_dict.items():
                if child == cur_child or parent == cur_child:
                    node_already_in_graph = True
                    if print_errors:
                        print(f"Cannot do '{parent}' -> '{child}'\n     when '{cur_parent}' -> '{cur_child}' has been done.\n")
                    errors = True
                    break
    
            if not node_already_in_graph:
                p_child = resolved_replacements_data_dict.get(parent)
                if p_child is not None:
                    if print_errors:
                        print(f"Cannot do '{parent}' -> '{child}'\n     when '{parent}' -> '{p_child}' has been done.\n")
                    errors = True
                else:
                    resolved_replacements_data_dict[parent] = child

        resolved_replacements_data = list(resolved_replacements_data_dict.items())
        #print(f"resolved_replacements_data: {resolved_replacements_data}")
        if errors and throw_error:
            if throw_error_message_prefix is None:
                throw_error_message_prefix = "Parsing errors occurred in replacement file. Below is the file trimmed to remove errors."

            output = io.StringIO()
            csv_writer = csv.writer(output)
            csv_writer.writerows(resolved_replacements_data)
            print(f"\n\n{throw_error_message_prefix}\n== Processed file ==\n{output.getvalue()}")
            sys.exit(1)

        return resolved_replacements_data, errors

class FileRenameData:
    @staticmethod
    def validate_rename_file_and_data(cur_filename, new_filename, file_renames_filename):
        FileRenameData.validate_rename_file(cur_filename, new_filename)

        file_renames_data = ReplacementData.read_in(file_renames_filename)
        ReplacementData.validate_and_resolve(file_renames_data, print_errors=True, throw_error=True)

        file_renames_data.append((cur_filename, new_filename))
        ReplacementData.validate_and_resolve(file_renames_data, print_errors=True, throw_error=True, throw_error_message_prefix=f"Renaming \"{cur_filename}\" to \"{new_filename}\" would have resulted in errors! Below would have been the resulting replacements file trimmed to remove errors.")

    @staticmethod
    def validate_rename_file(cur_filename, new_filename):
        cur_filepath = pathlib.Path(cur_filename)
        new_filepath = pathlib.Path(new_filename)

        if not cur_filepath.is_file():
            raise RuntimeError(f"{cur_filename} does not exist!")

        if new_filepath.exists():
            raise RuntimeError(f"Target filename {new_filename} already exists!")

    @staticmethod
    def rename_file(cur_filename, new_filename):
        pathlib.Path(new_filename).parent.mkdir(parents=True, exist_ok=True)
        os.rename(cur_filename, new_filename)

    @staticmethod
    def update_file_renames(cur_filename, new_filename, file_renames_filename):
        with open_l(file_renames_filename, "a") as f:
            file_renames_writer = csv.writer(f)
            file_renames_writer.writerow((cur_filename, new_filename))

    @staticmethod
    def rename_all_from_file(file_renames_filename, swapped):
        file_renames_data = ReplacementData.read_in(file_renames_filename)
        resolved_file_renames_data, errors = ReplacementData.validate_and_resolve(file_renames_data, print_errors=True, throw_error=True)
        #print(f"resolved_file_renames_data: {resolved_file_renames_data}")

        if swapped:
            resolved_file_renames_data = [(new_filename, cur_filename) for cur_filename, new_filename in resolved_file_renames_data]

        for cur_filename, new_filename in resolved_file_renames_data:
            FileRenameData.validate_rename_file(cur_filename, new_filename)
            FileRenameData.rename_file(cur_filename, new_filename)

class FilesSingleReplacer:
    @staticmethod
    def replace_single(filenames, replace_from, replace_to, replacements_filename):
        replacements_data = ReplacementData.read_in(replacements_filename)
        ReplacementData.validate_and_resolve(replacements_data, print_errors=True, throw_error=True)

        replacements_data.append((replace_from, replace_to))
        ReplacementData.validate_and_resolve(replacements_data,
            print_errors=True, throw_error=True,
            throw_error_message_prefix=f"Performing the replacement '{replace_from}' -> '{replace_to}' resulted in errors! Below would have been the resulting file trimmed to remove errors."
        )

        replace_results = {}

        print(f"Searching through files!")
        for filename in filenames:
            replace_result, num_replacements = Replacer.single_replace_for_file_result_only(filename, replace_from, replace_to)
            if num_replacements != 0:
                replace_results[filename] = replace_result

        print(f"Writing files, do not interrupt!")
        for filename, replace_result in replace_results.items():
            with open_l(filename, "w+") as f:
                f.write(replace_result)

        with open_l(replacements_filename, "a") as f:
            replacements_writer = csv.writer(f)
            replacements_writer.writerow([replace_from, replace_to])

class FilesMultiReplacer:
    __slots__ = ("data", "resolved_data", "replacements_filename")

    def __init__(self, replacements_filename):
        data = ReplacementData.read_in(replacements_filename)
        self.resolved_data, errors = ReplacementData.validate_and_resolve(data, print_errors=True, throw_error=True)

        self.data = data
        self.replacements_filename = replacements_filename

    def create_rep_dict(self, given_data, swapped):
        if swapped:
            rep_dict = {replace_to: replace_from for replace_from, replace_to in given_data}
        else:
            rep_dict = {replace_from: replace_to for replace_from, replace_to in given_data}

        return rep_dict

    def replace_multiple(self, filenames, rep_dict):
        replace_results = {}

        print(f"Searching through files!")
        multiple_replace_pattern = Replacer.create_multiple_replace_pattern(rep_dict)

        for filename in filenames:
            #print(f"filename: {filename}")
            replace_result, num_replacements = Replacer.multiple_replace_for_file_result_only(filename, multiple_replace_pattern, rep_dict)
            if num_replacements != 0:
                print(f"replaced in {filename}")
                replace_results[filename] = replace_result

        print(f"Writing files, do not interrupt!")
        for filename, replace_result in replace_results.items():
            with open_l(filename, "w+") as f:
                f.write(replace_result)

    def unreplace(self, filenames):
        rep_dict = self.create_rep_dict(self.resolved_data, True)
        print(f"unreplace rep_dict: {rep_dict}")
        self.replace_multiple(filenames, rep_dict)

    def rereplace(self, filenames):
        rep_dict = self.create_rep_dict(self.resolved_data, False)
        self.replace_multiple(filenames, rep_dict)

    def add_replacements_and_replace_multiple(self, filenames, data_to_add):
        new_data = self.data + data_to_add
        ReplacementData.validate_and_resolve(new_data, print_errors=True, throw_error=True, throw_error_message_prefix=f"Performing the replacements " + "; ".join(f"'{replace_from}' -> '{replace_to}'" for replace_from, replace_to in data_to_add) + " resulted in errors! Below would have been the resulting file trimmed to remove errors.")

        rep_dict = self.create_rep_dict(data_to_add, False)
        self.replace_multiple(filenames, rep_dict)

        with open_l(self.replacements_filename, "a") as f:
            replacements_writer = csv.writer(f)
            replacements_writer.writerows(data_to_add)

    def clear_csv(self):
        with open_l(self.replacements_filename, "w+") as f:
            pass

# pokeheartgold is "{asm,include,lib,src,sub}/**/*.{c,h,inc,s}"

def read_in_all_code_files(code_files_glob_filename):
    with open_l(code_files_glob_filename, "r") as f:
        glob_specifier = f.read().strip()

    return wcmatch_glob.glob(glob_specifier, flags=(wcmatch_glob.GLOBSTAR | wcmatch_glob.BRACE | wcmatch_glob.NEGATE))
