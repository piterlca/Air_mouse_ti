################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3

ORDERED_OBJS += \
"./Clksetting.obj" \
"./TaskMgr.obj" \
"./TimerInit.obj" \
"./i2c_conf.obj" \
"./i2c_configuration.obj" \
"./main.obj" \
"./Ring_buffer/ring_buffer.obj" \
"./MPU-6050/MPU-6050.obj" \
"./I2C/i2c_pvt.obj" \
"../lnk_msp430fr4133.cmd" \
$(GEN_CMDS__FLAG) \
-l"libc.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Ring_buffer/subdir_vars.mk
-include MPU-6050/subdir_vars.mk
-include I2C/subdir_vars.mk
-include subdir_rules.mk
-include Ring_buffer/subdir_rules.mk
-include MPU-6050/subdir_rules.mk
-include I2C/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
HelloWorld.out \

EXE_OUTPUTS__QUOTED += \
"HelloWorld.out" \

BIN_OUTPUTS += \
HelloWorld.hex \

BIN_OUTPUTS__QUOTED += \
"HelloWorld.hex" \


# All Target
all: HelloWorld.out

# Tool invocations
HelloWorld.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP430 Linker'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/bin/cl430" -vmspx --abi=eabi --use_hw_mpy=none --advice:power=all --advice:hw_config=all -g --define=__MSP430FR4133__ --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal -z -m"HelloWorld.map" --heap_size=160 --stack_size=160 --cinit_hold_wdt=on -i"C:/ti/ccsv6/ccs_base/msp430/include" -i"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/lib" -i"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/include" --reread_libs --warn_sections --display_error_number --diag_wrap=off --xml_link_info="HelloWorld_linkInfo.xml" --use_hw_mpy=none --rom_model -o "HelloWorld.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

HelloWorld.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: MSP430 Hex Utility'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/bin/hex430" --memwidth=8 --romwidth=8 -o "HelloWorld.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "Clksetting.pp" "TaskMgr.pp" "TimerInit.pp" "i2c_conf.pp" "i2c_configuration.pp" "main.pp" "Ring_buffer\ring_buffer.pp" "MPU-6050\MPU-6050.pp" "I2C\i2c_pvt.pp" 
	-$(RM) "Clksetting.obj" "TaskMgr.obj" "TimerInit.obj" "i2c_conf.obj" "i2c_configuration.obj" "main.obj" "Ring_buffer\ring_buffer.obj" "MPU-6050\MPU-6050.obj" "I2C\i2c_pvt.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

