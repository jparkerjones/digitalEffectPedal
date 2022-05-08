################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/applyEffects.c \
../Core/Src/bitcrusherEffect.c \
../Core/Src/chorusEffect.c \
../Core/Src/codec.c \
../Core/Src/delayEffect.c \
../Core/Src/dma.c \
../Core/Src/gpio.c \
../Core/Src/i2c.c \
../Core/Src/i2s.c \
../Core/Src/main.c \
../Core/Src/navswitch.c \
../Core/Src/rotaryScale.c \
../Core/Src/rtc.c \
../Core/Src/spi.c \
../Core/Src/stm32h7xx_hal_msp.c \
../Core/Src/stm32h7xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32h7xx.c \
../Core/Src/tim.c \
../Core/Src/tremoloEffect.c \
../Core/Src/undersamplingEffect.c 

OBJS += \
./Core/Src/applyEffects.o \
./Core/Src/bitcrusherEffect.o \
./Core/Src/chorusEffect.o \
./Core/Src/codec.o \
./Core/Src/delayEffect.o \
./Core/Src/dma.o \
./Core/Src/gpio.o \
./Core/Src/i2c.o \
./Core/Src/i2s.o \
./Core/Src/main.o \
./Core/Src/navswitch.o \
./Core/Src/rotaryScale.o \
./Core/Src/rtc.o \
./Core/Src/spi.o \
./Core/Src/stm32h7xx_hal_msp.o \
./Core/Src/stm32h7xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32h7xx.o \
./Core/Src/tim.o \
./Core/Src/tremoloEffect.o \
./Core/Src/undersamplingEffect.o 

C_DEPS += \
./Core/Src/applyEffects.d \
./Core/Src/bitcrusherEffect.d \
./Core/Src/chorusEffect.d \
./Core/Src/codec.d \
./Core/Src/delayEffect.d \
./Core/Src/dma.d \
./Core/Src/gpio.d \
./Core/Src/i2c.d \
./Core/Src/i2s.d \
./Core/Src/main.d \
./Core/Src/navswitch.d \
./Core/Src/rotaryScale.d \
./Core/Src/rtc.d \
./Core/Src/spi.d \
./Core/Src/stm32h7xx_hal_msp.d \
./Core/Src/stm32h7xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32h7xx.d \
./Core/Src/tim.d \
./Core/Src/tremoloEffect.d \
./Core/Src/undersamplingEffect.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/ST7735 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/applyEffects.d ./Core/Src/applyEffects.o ./Core/Src/bitcrusherEffect.d ./Core/Src/bitcrusherEffect.o ./Core/Src/chorusEffect.d ./Core/Src/chorusEffect.o ./Core/Src/codec.d ./Core/Src/codec.o ./Core/Src/delayEffect.d ./Core/Src/delayEffect.o ./Core/Src/dma.d ./Core/Src/dma.o ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/i2c.d ./Core/Src/i2c.o ./Core/Src/i2s.d ./Core/Src/i2s.o ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/navswitch.d ./Core/Src/navswitch.o ./Core/Src/rotaryScale.d ./Core/Src/rotaryScale.o ./Core/Src/rtc.d ./Core/Src/rtc.o ./Core/Src/spi.d ./Core/Src/spi.o ./Core/Src/stm32h7xx_hal_msp.d ./Core/Src/stm32h7xx_hal_msp.o ./Core/Src/stm32h7xx_it.d ./Core/Src/stm32h7xx_it.o ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/system_stm32h7xx.d ./Core/Src/system_stm32h7xx.o ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tremoloEffect.d ./Core/Src/tremoloEffect.o ./Core/Src/undersamplingEffect.d ./Core/Src/undersamplingEffect.o

.PHONY: clean-Core-2f-Src

