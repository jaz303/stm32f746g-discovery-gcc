MCPU 				:= cortex-m7
PART 				:= STM32F746xx

TOOLCHAIN			?= arm-none-eabi-
CC 					:= $(TOOLCHAIN)gcc
AS 					:= $(TOOLCHAIN)as
LD 					:= $(TOOLCHAIN)gcc
OBJCOPY				:= $(TOOLCHAIN)objcopy

BUILD 				:= build
DEPS 				:= .deps

PRODUCT_NAME		:= test
PRODUCT_BASE		:= $(BUILD)/$(PRODUCT_NAME)
PRODUCT_ELF 		:= $(PRODUCT_BASE).elf
PRODUCT_HEX			:= $(patsubst %.elf,%.hex,$(PRODUCT_ELF))
PRODUCT_BIN			:= $(patsubst %.elf,%.bin,$(PRODUCT_ELF))

# Project source
PROJ_SRC 			:= $(shell find src -name '*.c' -or -name '*.cpp' -or -name '*.s')
PROJ_OBJ 			:= $(addsuffix .o,$(basename $(PROJ_SRC)))

# CMSIS
CMSIS_DIR 			:= ../../lib/Drivers/CMSIS
CMSIS_DEVICE_DIR	:= $(CMSIS_DIR)/Device/ST/STM32F7xx

# HAL setup
HAL_DIR 			:= ../../lib/Drivers/STM32F7xx_HAL_Driver
HAL_INC 			:= $(HAL_DIR)/Inc
HAL_SRC 			:= $(shell find $(HAL_DIR)/Src -name '*.c')
HAL_OBJ_DIR			:= $(DEPS)/hal
HAL_OBJ				:= $(patsubst %.c,%.o,$(addprefix $(HAL_OBJ_DIR)/, $(notdir $(HAL_SRC))))

# Include path
INCLUDE := -Iinclude -Iconfig
INCLUDE += -I$(CMSIS_DEVICE_DIR)/Include
INCLUDE += -I$(CMSIS_DIR)/Include
INCLUDE += -I$(HAL_INC)

FLAGS := -mcpu=$(MCPU) -mthumb
CFLAGS := $(FLAGS) $(INCLUDE) -D$(PART)
LDFLAGS := -specs=nosys.specs -Wl,--gc-sections $(FLAGS)
ASFLAGS := $(FLAGS)

$(HAL_OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

default: $(PRODUCT_ELF) $(PRODUCT_BIN) $(PRODUCT_HEX)

$(HAL_OBJ_DIR):
	mkdir -p $(HAL_OBJ_DIR)

$(PRODUCT_ELF): $(BUILD) obj
	$(LD) -T stm32f746.ld $(LDFLAGS) -o $@ $(HAL_OBJ) $(PROJ_OBJ)

$(PRODUCT_BIN): $(PRODUCT_ELF)
	$(OBJCOPY) -O binary $< $@

$(PRODUCT_HEX): $(PRODUCT_ELF)
	$(OBJCOPY) -O ihex $< $@

$(BUILD):
	mkdir -p $(BUILD)

hal_obj: $(HAL_OBJ_DIR) $(HAL_OBJ)

obj: hal_obj $(PROJ_OBJ)

vpath %.c $(HAL_DIR)/Src


clean:
	rm -rf .deps $(PROJ_OBJ)

.PHONY: hal_obj obj clean
