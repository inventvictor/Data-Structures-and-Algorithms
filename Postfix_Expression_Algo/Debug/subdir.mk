################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../arrayStack.c \
../infix_to_postfix_algo.c \
../intArrayStack.c 

OBJS += \
./arrayStack.o \
./infix_to_postfix_algo.o \
./intArrayStack.o 

C_DEPS += \
./arrayStack.d \
./infix_to_postfix_algo.d \
./intArrayStack.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


