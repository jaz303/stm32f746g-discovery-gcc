# STM32F746G-DISCOVERY-GCC

This is a workspace for developing with the [STM32F746G-DISCO](http://www.st.com/web/en/catalog/tools/FM116/SC959/SS1532/LN1848/PF261641?icmp=pf261641_pron_pr-massmarket_jun2015&sc=stm32f7discovery-pr) evaluation kit, providing a Makefile-based project layout supporting the HAL and CMSIS layers, plus per-peripheral BSP configuration. It's set up with multiple projects in mind.

## How to use

  - Install an ARM toolchain. I'm using [Canonical's](https://launchpad.net/gcc-arm-embedded) (they provide builds for Linux, OS X and Windows).

## Building a test project

  * Ensure toolchain is in your `$PATH`.
  * Create a project based on the `test` template:

    $ ./create-project my-first-project test

  * Build the new project
    
    $ cd proj/my-first-project
    $ make

## Credits

Linker script is from the Micropython project.