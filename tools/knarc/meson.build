c_srcs = []

if build_machine.system() == 'windows'
    c_srcs += 'fnmatch.c'
endif

cpp_scrs = [
    'Source.cpp',
    'Narc.cpp'
]

knarc_exe = executable('knarc',
    sources: [
        c_srcs,
        cpp_scrs
    ],
    native: true
)