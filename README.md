# STM32F746G-DISCOVERY-GCC

This is a workspace for developing with the [STM32F746G-DISCO](http://www.st.com/web/en/catalog/tools/FM116/SC959/SS1532/LN1848/PF261641?icmp=pf261641_pron_pr-massmarket_jun2015&sc=stm32f7discovery-pr) evaluation kit, providing a Makefile-based project layout supporting the HAL and CMSIS layers, plus per-peripheral BSP configuration. It's set up with multiple projects in mind.

## How to use

  - Install an ARM toolchain. I'm using [Canonical's](https://launchpad.net/gcc-arm-embedded), who provide builds for Linux, OS X and Windows

## Building the test project

Ensure your toolchain is in your `$PATH`.

    cd proj/test
    make

## Credits

Linker script is from the Micropython project.