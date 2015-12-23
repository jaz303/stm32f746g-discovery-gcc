# STM32F746G-DISCOVERY-GCC

This is a workspace for developing with the [STM32F746G-DISCO](http://www.st.com/web/en/catalog/tools/FM116/SC959/SS1532/LN1848/PF261641?icmp=pf261641_pron_pr-massmarket_jun2015&sc=stm32f7discovery-pr) evaluation kit, providing a Makefile-based project layout supporting the HAL and CMSIS layers, plus per-peripheral BSP configuration. It's set up with multiple projects in mind.

## Layout

  * `lib`: a pared down distribution of `STM32Cube_FW_F7_V1.3.0`, including only BSP, CMSIS and HAL layers. All documentation, examples and middlware has been removed. The directory structure of the original distribution is preserved. Please refer to the `STM32Cube_FW_F7_V1.3.0` distribution for licensing information.

  * `proj`: projects go here. Use the `create-project` script to create one.

  * `template`: pristine project templates.

## How to use

  - Install an ARM toolchain. I'm using [Canonical's](https://launchpad.net/gcc-arm-embedded) (they provide builds for Linux, OS X and Windows).
  - Install [stlink](https://github.com/texane/stlink)

## Building a test project

  * Ensure toolchain is in your `$PATH`.
  * Create a project based on the `test` template: `$ ./create-project my-first-project test`
  * Build the new project: `$ cd proj/my-first-project; make`

## Credits

Linker script is from the Micropython project.