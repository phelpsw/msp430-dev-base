# List unit test files
tests = ['test_delay.c', 
         'test_delay2.c',
         'test_leds.c',
        ]

# List driverlib files to generate mocks for
mock_driverlib_headers = ['gpio.h']


prog_ruby = find_program('ruby')
prog_mv = find_program('mv')
test_generator = files('../external/unity/auto/generate_test_runner.rb')
mock_generator = files('../external/cmock/lib/cmock.rb')

# Generate mock files
driverlib_mock_srcs = []
foreach m_file : mock_driverlib_headers
    m_name = m_file.split('.')[0]
    m_input = files('../' + driverlib_path + m_file)
    mock_ch = custom_target('mock_' + m_name + '.[ch]',
                             input : m_input,
                             output : ['mock_' + m_name + '.h', 
                                       'mock_' + m_name + '.c'],
                             command : [prog_ruby, mock_generator,
                                        '-o../mock_config.yml', '@INPUT@'])
    driverlib_mock_srcs += [mock_ch]
endforeach

foreach t_file : tests
	t_name = t_file.split('.')[0]
    # Generate unity tests, because output location can't be specified
    # required to play mv games to locate generated file in correct location
    gen_src = custom_target(t_name + '_Runner.c',
                            input : t_file,
                            output : t_name + '_Runner.c',
                            command : [prog_ruby, test_generator, '@INPUT@',
                                '&&', prog_mv, '../@OUTPUT@', '@OUTDIR@/'
                            ])

    testexe = executable(t_name, t_file, gen_src, driverlib_mock_srcs,
                        include_directories : [inc,
                                               driverlib_inc,
                                               msp430_inc,
                                               unity_dir,
                                               cmock_dir],
                        link_with : [libproject, unity_lib, cmock_lib])
    test(t_name + ' test', testexe)
endforeach