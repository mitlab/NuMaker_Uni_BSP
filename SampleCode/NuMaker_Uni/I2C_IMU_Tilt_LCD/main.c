//
// I2C_IMU_Tilt_LCD : read Accelerometer to calculate tilt angles and display on LCD
//
// EVB : NuMaker Uni
// MCU : Nano102ZC2AN
// IMU : MPU6500
// LCD : 0.96" OLED 128x64

// JP6 connections
// PA9 /I2C0-SCL to LCD's SCL
// PA8 /I2C0-SDA to LCD's SDA
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
#include "I2C_SSD1306Z.h"
#define PI 3.14159265359

int32_t main()
{
    char Text[16];
    int16_t accX, accY, accZ;
    float theta, psi, phi;
	
    SYS_Init();	
    I2C_Open(I2C0, I2C0_CLOCK_FREQUENCY);
    I2C_Open(I2C1, I2C1_CLOCK_FREQUENCY);
    Init_MPU6500();
    init_LCD();
    clear_LCD();
    print_Line(0,"IMU Tilt Angle");
	
    while(1) {
      accX = Read_MPU6500_AccX();
      accY = Read_MPU6500_AccY();
      accZ = Read_MPU6500_AccZ();

      // calculate tilt (degree = radians *180 / PI)
      theta = atan(accX / sqrt(pow(accY,2)+pow(accZ,2))) *180 /PI;		
      psi   = atan(accY / sqrt(pow(accX,2)+pow(accZ,2))) *180 /PI;
      phi   = atan(sqrt(pow(accX,2)+pow(accY,2))/accZ)   *180 /PI;
      sprintf(Text,"theta=%4d", (int) theta); print_Line(1,Text);
      sprintf(Text,"psi  =%4d", (int) psi);   print_Line(2,Text);
      sprintf(Text,"phi  =%4d", (int) phi);   print_Line(3,Text);
    }
}
