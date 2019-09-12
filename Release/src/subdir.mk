################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Agency.cpp \
../src/BinDecoder.cpp \
../src/BinEncoder.cpp \
../src/DataQuality.cpp \
../src/DataResolution.cpp \
../src/DepthCalculator.cpp \
../src/FormatConverter.cpp \
../src/Launchers.cpp \
../src/MessageType.cpp \
../src/PressureCalculator.cpp \
../src/SoundSpeedInSeaWater.cpp \
../src/SurfaceCurrentInstrument.cpp \
../src/WindInstrument.cpp \
../src/XBTProbe.cpp \
../src/XBTProfile.cpp \
../src/XBTProfileDataRanges.cpp \
../src/XBTRecorder.cpp \
../src/XBTResistanceToTemperatureConverter.cpp 

OBJS += \
./src/Agency.o \
./src/BinDecoder.o \
./src/BinEncoder.o \
./src/DataQuality.o \
./src/DataResolution.o \
./src/DepthCalculator.o \
./src/FormatConverter.o \
./src/Launchers.o \
./src/MessageType.o \
./src/PressureCalculator.o \
./src/SoundSpeedInSeaWater.o \
./src/SurfaceCurrentInstrument.o \
./src/WindInstrument.o \
./src/XBTProbe.o \
./src/XBTProfile.o \
./src/XBTProfileDataRanges.o \
./src/XBTRecorder.o \
./src/XBTResistanceToTemperatureConverter.o 

CPP_DEPS += \
./src/Agency.d \
./src/BinDecoder.d \
./src/BinEncoder.d \
./src/DataQuality.d \
./src/DataResolution.d \
./src/DepthCalculator.d \
./src/FormatConverter.d \
./src/Launchers.d \
./src/MessageType.d \
./src/PressureCalculator.d \
./src/SoundSpeedInSeaWater.d \
./src/SurfaceCurrentInstrument.d \
./src/WindInstrument.d \
./src/XBTProbe.d \
./src/XBTProfile.d \
./src/XBTProfileDataRanges.d \
./src/XBTRecorder.d \
./src/XBTResistanceToTemperatureConverter.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -I"/home/pedro/eclipse-workspace/xbtbinfileutils/include" -O3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


