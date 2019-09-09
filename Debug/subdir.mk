################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Agency.cpp \
../BinDecoder.cpp \
../BinEncoder.cpp \
../DataQuality.cpp \
../DataResolution.cpp \
../DepthCalculator.cpp \
../FormatConverter.cpp \
../Launchers.cpp \
../MessageType.cpp \
../PressureCalculator.cpp \
../SoundSpeedInSeaWater.cpp \
../SurfaceCurrentInstrument.cpp \
../WindInstrument.cpp \
../XBTProbe.cpp \
../XBTProfile.cpp \
../XBTProfileDataRanges.cpp \
../XBTRecorder.cpp \
../XBTResistanceToTemperatureConverter.cpp 

OBJS += \
./Agency.o \
./BinDecoder.o \
./BinEncoder.o \
./DataQuality.o \
./DataResolution.o \
./DepthCalculator.o \
./FormatConverter.o \
./Launchers.o \
./MessageType.o \
./PressureCalculator.o \
./SoundSpeedInSeaWater.o \
./SurfaceCurrentInstrument.o \
./WindInstrument.o \
./XBTProbe.o \
./XBTProfile.o \
./XBTProfileDataRanges.o \
./XBTRecorder.o \
./XBTResistanceToTemperatureConverter.o 

CPP_DEPS += \
./Agency.d \
./BinDecoder.d \
./BinEncoder.d \
./DataQuality.d \
./DataResolution.d \
./DepthCalculator.d \
./FormatConverter.d \
./Launchers.d \
./MessageType.d \
./PressureCalculator.d \
./SoundSpeedInSeaWater.d \
./SurfaceCurrentInstrument.d \
./WindInstrument.d \
./XBTProbe.d \
./XBTProfile.d \
./XBTProfileDataRanges.d \
./XBTRecorder.d \
./XBTResistanceToTemperatureConverter.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


