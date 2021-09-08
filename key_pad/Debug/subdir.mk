<<<<<<< HEAD
################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
=======
################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
>>>>>>> 50770696eabc6891b153c0666b8d9d5b1191c063
C_SRCS += \
../gpio.c \
../keypad.c \
../lcd.c \
<<<<<<< HEAD
../main.c 

=======
../main.c 

>>>>>>> 50770696eabc6891b153c0666b8d9d5b1191c063
OBJS += \
./gpio.o \
./keypad.o \
./lcd.o \
<<<<<<< HEAD
./main.o 

=======
./main.o 

>>>>>>> 50770696eabc6891b153c0666b8d9d5b1191c063
C_DEPS += \
./gpio.d \
./keypad.d \
./lcd.d \
<<<<<<< HEAD
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


=======
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


>>>>>>> 50770696eabc6891b153c0666b8d9d5b1191c063
