//
// I2C_IMU_Tilt : read Accelerometer to calculate tilt angles
//
// EVB : NuMaker Uni
// MCU : NANO100NE3BN
// IMU : MPU6500

// I2C1 to IMU connections
// PA11/I2C1-SCL to IMU's SCL
// PA10/I2C1-SDA to IMU's SDA

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
    float theta, psi, phi;
	
    SYS_Init();	
    I2C_Open(I2C1, I2C1_CLOCK_FREQUENCY);
    Init_MPU6500();
	
    while(1) {
			accX = Read_MPU6500_AccX();
			accY = Read_MPU6500_AccY();
			accZ = Read_MPU6500_AccZ();		
			printf("Accel: %6d, %6d, %6d, ", accX, accY, accZ);
			
			// calculate tilt (degree = radians *180 / PI)
			theta = atan(accX / sqrt(pow(accY,2)+pow(accZ,2))) *180 /PI;		
			psi   = atan(accY / sqrt(pow(accX,2)+pow(accZ,2))) *180 /PI;
			phi   = atan(sqrt(pow(accX,2)+pow(accY,2))/accZ)   *180 /PI;
			printf("theta=%d, psi=%d, phi=%d\n", (int) theta, (int) psi, (int) phi);			
    }
}
