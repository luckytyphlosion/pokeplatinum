nuts_data_format_txt     = files('nuts_data_format.txt')
nuts_data_csv            = files('nuts_data.csv')

nuts_data_narc = custom_target('nuts_data.narc',
    output: 'nuts_data.narc',
    input: [
        nuts_data_format_txt,
        nuts_data_csv
    ], 
    command: [
        csv2bin_exe,
        'compile',
        '@INPUT1@',
        '@OUTPUT0@',
        '@INPUT0@',
        '--narc',
        '-i', '@SOURCE_ROOT@/include'
    ]
)

pl_item_data_format_txt     = files('pl_item_data_format.txt')
pl_item_data_csv            = files('pl_item_data.csv')

pl_item_data_narc = custom_target('pl_item_data.narc',
    output: 'pl_item_data.narc',
    input: [
        pl_item_data_format_txt,
        pl_item_data_csv
    ], 
    command: [
        csv2bin_exe,
        'compile',
        '@INPUT1@',
        '@OUTPUT0@',
        '@INPUT0@',
        '--narc',
        '--pad', '0xFF',
        '-i', '@SOURCE_ROOT@/include'
    ]
)

nitrofs_files += nuts_data_narc
nitrofs_files += pl_item_data_narc

prebuilt_files = [
    'item_data.narc',
    'item_icon.narc'
]

foreach f : prebuilt_files
    nitrofs_files += fs.copyfile(f)
endforeach
