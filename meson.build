project('pwtest', 'c',
  version : '0.0.1')

add_global_arguments('-D__MSP430FR5969__', language : 'c')

msp430_inc = include_directories('/usr/local/msp430/include/')

driverlib_path = 'external/msp430-driverlib/driverlib/MSP430FR5xx_6xx/'
driverlib_inc = include_directories(driverlib_path)
driverlib_src = [driverlib_path + 'gpio.c']
driverlib_lib = static_library('_ti_driverlib', driverlib_src,
                        include_directories : [driverlib_inc, msp430_inc])

subdir('include')
subdir('src')

if not meson.is_cross_build()
  subdir('external/unity/src')
  unity_dep = declare_dependency(
      link_with : unity_lib,
      include_directories : unity_dir
  )
  subdir('external/cmock/src')
  subdir('test')
endif