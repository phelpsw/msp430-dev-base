sources = ['delay.c', 'leds.c']
libproject = static_library('project', sources,
                            include_directories : [inc, msp430_inc, driverlib_inc])

if meson.is_cross_build()
    mspdebug = find_program('mspdebug', required : true)
    
    binaries = [
        ['blink.elf', ['blink_bin.c'], 'msp430fr5969'],
    ]

    t_mspflash = 'flash_@0@'
    t_mspchip = '-mmcu=@0@'
    t_msplink = '/usr/local/msp430/include/@0@.ld'

    foreach bin : binaries
        e = executable(bin[0], bin[1],
            c_args : [t_mspchip.format(bin[2])],
            link_with : [driverlib_lib, libproject],
            link_args : [
                        '--verbose',
                        t_mspchip.format(bin[2]),
                        '-L/usr/local/msp430/include/',
            ],
            link_depends: files([t_msplink.format(bin[2])]),
            include_directories : [inc, driverlib_inc, msp430_inc]
        )
        r = run_target(t_mspflash.format(bin[0]),
	    	command : [mspdebug, 'tilib', 'prog @0@'.format(e.full_path())],
	    	depends : e,
	    )
        message('@0@ targets: @0@ @1@'.format(bin[0], t_mspflash.format(bin[0])))
    endforeach
endif