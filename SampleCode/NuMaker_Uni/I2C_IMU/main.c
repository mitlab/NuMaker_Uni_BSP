//
// I2C_MPU6500 : use I2C to read IMU and print on Debug Session View
//
// EVB : NuMaker Uni
// MCU : NANO100NE3BN
// IMU : MPU6500

// I2C1 to IMU
// PA11/I2C0-SCL to IMU's SCL
// PA10/I2C0-SDA to IMU's SDA

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "MPU6500.h"
#define PI 3.14159265359

int32_t main()
{
    int16_t accX, accY, accZ;
    int16_t gyroX, gyroY, gyroZ;
	
    SYS_Init();	
    I2C_Open(I2C1, I2C1_CLOCK_FREQUENCY);	
    Init_MPU6500();
	
    while(1) {
      accX = Read_MPU6500_AccX();
      accY = Read_MPU6500_AccY();
      accZ = Read_MPU6500_AccZ();		
      printf("Accel: %6d, %6d, %6d, ", accX, accY, accZ);
      gyroX = Read_MPU6500_GyroX();
      gyroY = Read_MPU6500_GyroY();
      gyroZ = Read_MPU6500_GyroZ();		
      printf("Gyro : %6d, %6d, %6d\n", gyroX, gyroY, gyroZ);			
    }
}
