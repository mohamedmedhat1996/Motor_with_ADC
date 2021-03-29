################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO.c \
../My_Keypad.c \
../My_Lcd.c \
../My_adc.c \
../Timer.c \
../main.c 

OBJS += \
./GPIO.o \
./My_Keypad.o \
./My_Lcd.o \
./My_adc.o \
./Timer.o \
./main.o 

C_DEPS += \
./GPIO.d \
./My_Keypad.d \
./My_Lcd.d \
./My_adc.d \
./Timer.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


