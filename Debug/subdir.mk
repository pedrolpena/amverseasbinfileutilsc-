################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Agency.cpp \
../BinDecoder.cpp \
../DataQuality.cpp \
../DataResolution.cpp \
../Launchers.cpp \
../MessageType.cpp \
../XBTProbe.cpp \
../XBTProfile.cpp \
../XBTProfileDataRanges.cpp \
../XBTRecorder.cpp \
../XBTResistanceToTemperatureConverter.cpp 

OBJS += \
./Agency.o \
./BinDecoder.o \
./DataQuality.o \
./DataResolution.o \
./Launchers.o \
./MessageType.o \
./XBTProbe.o \
./XBTProfile.o \
./XBTProfileDataRanges.o \
./XBTRecorder.o \
./XBTResistanceToTemperatureConverter.o 

CPP_DEPS += \
./Agency.d \
./BinDecoder.d \
./DataQuality.d \
./DataResolution.d \
./Launchers.d \
./MessageType.d \
./XBTProbe.d \
./XBTProfile.d \
./XBTProfileDataRanges.d \
./XBTRecorder.d \
./XBTResistanceToTemperatureConverter.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


