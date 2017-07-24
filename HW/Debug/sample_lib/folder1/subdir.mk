################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../sample_lib/folder1/file1.c 

OBJS += \
./sample_lib/folder1/file1.o 

C_DEPS += \
./sample_lib/folder1/file1.d 


# Each subdirectory must supply rules for building sources it contributes
sample_lib/folder1/%.o: ../sample_lib/folder1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


