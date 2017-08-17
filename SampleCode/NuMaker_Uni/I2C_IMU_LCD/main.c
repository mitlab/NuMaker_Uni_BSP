//
// I2C_IMU_LCD : use I2C to read IMU and display on LCD
//
// EVB : NuMaker Uni
// MCU : NANO100NE3BN
// IMU : MPU6500
// LCD : 0.96" OLED 128x64

// JP2 connection
// PA9/I2C0-SCL to LCD's SCL
// PA8/I2C0-SDA to LCD's SDA

// I2C1 to IMU 
// PA11/I2C1-SCL to IMU's SCL
// PA10/I2C1-SDA to IMU's SDA

#include <stdio.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "MPU6500.h"
#include "I2C_SSD1306Z.h"

int32_t main()
{
    char Text[16];
    int16_t accX, accY, accZ;
    int16_t gyroX, gyroY, gyroZ;
	
    SYS_Init();	
    I2C_Open(I2C0, I2C0_CLOCK_FREQUENCY);
    I2C_Open(I2C1, I2C1_CLOCK_FREQUENCY);
    Init_MPU6500();
    init_LCD();
    clear_LCD();
	
    print_Line(0,"IMU LCD Demo");
    while(1) {
      accX = Read_MPU6500_AccX();
      accY = Read_MPU6500_AccY();
      accZ = Read_MPU6500_AccZ();
      gyroX= Read_MPU6500_GyroX();
      gyroY= Read_MPU6500_GyroY();
      gyroZ= Read_MPU6500_GyroZ();
      sprintf(Text,"%6d, %6d", accX, gyroX); print_Line(1, Text);
      sprintf(Text,"%6d, %6d", accY, gyroY); print_Line(2, Text);
      sprintf(Text,"%6d, %6d", accZ, gyroZ); print_Line(3, Text);			
    }
}
