# MSP430 Development Environment Example

This repo provides a basic msp430 development environment based on the supported TI GCC toolchain but configured in a reproducible manner inside a docker container.  Additionally leveraged is the vscode extension allowing Remote Development inside a docker container meaning none of the development tools need to be installed on the development machine directly and instead run within the container dev environment.  Getting the correct toolchain, debug, target loading tools consistently installed is traditionally the source of many headaches for embedded developers.  TI's driverlib is also included, useful for simplifying many aspects of interacting with microcontroller hardware interfaces.  Meson and ninja are used as the build system.

VScode tasks are setup for loading and remote debugging of the msp430 target.  CMock and Unity are used to enable a mocked unit test environment natively on the development host.  Additionally the mocking allows for testing of functions leveraging the driverlib library.

Because the development environment is containerized, integration into ci/cd pipelines is relatively trivial, another common challenge for embedded development.

This project demonstrates a simple led blinking demo based on driverlib and the [EXP430FR5969](https://www.ti.com/tool/MSP-EXP430FR5969) development board / launchpad.

This is in line with what I believe embedded development platforms like TI's CCS should look like, stripping away some of the extreme optimization features and instead building in standard software development requirements like unit testing and non-proprietary toolchains, build systems, programming and debugging tools.  The use of VSCode here is a little contradictory but unlike CCS, to my knowledge, it isn't required for building, testing, programming, or debugging, merely to facilitate development.

Constituent Components
 - The base remote development environment container is [phelpsw/msp430-build](https://github.com/phelpsw/msp430-build) and is available via [dockerhub](https://hub.docker.com/r/phelpsw/msp430-build).
 - Driverlib is maintained as a separate repository here and configured as a submodule
 - [CMock](https://github.com/ThrowTheSwitch/CMock) and [Unity](https://github.com/ThrowTheSwitch/Unity) are setup as submodules
 - The remainder of the necessary components are in this repository
 
# Other stuff:
 - Warnings from mismatched types in unit test builds
 - debug, debug_optimized, release build distinction
 - Add mock path to vscode intellisense
 - automatic mock generation based on driverlib_src
 - cleanup link args for msp430 executable build
 - driverlib -Werror=parentheses issues in timer libs
 - vscode defines
 - when unit tests fail they should show relevant log segments
 - code coverage report