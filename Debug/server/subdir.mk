################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../server/ServerBase.cpp \
../server/ServerMain.cpp 

OBJS += \
./server/ServerBase.o \
./server/ServerMain.o 

CPP_DEPS += \
./server/ServerBase.d \
./server/ServerMain.d 


# Each subdirectory must supply rules for building sources it contributes
server/%.o: ../server/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=gnu++11 -DDEBUG_MODE=1 -I/home/ruanbo/Codes/ImServer/ -I/home/ruanbo/Codes/RuboServer -I/usr/local/include/c++/5.2.0 -I/usr/local/include/c++/5.2.0/x86_64-unknown-linux-gnu -I/usr/local/include/c++/5.2.0/backward -I/home/ruanbo/Codes/ImServer/ImServer/ImServer -I/usr/include/mysql -I/usr/local/protobuf/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


