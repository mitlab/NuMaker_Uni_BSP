//
// MPU6500 Driver: 3-axis Gyroscope + 3-axis accelerometer + temperature
//
// Interface: I2C
// pin1: Vcc to Vcc (+5V)
// pin2: Gnd to Gnd
// pin3: SCL to I2C1_SCL/PC10
// pin4: SDA to I2C1_SDA/PC11
// pin5: XDA -- N.C.
// pin6: XCL -- N.C.
// pin7: AD0 -- N.C.
// pin8: INT -- N.C.

#include <stdio.h>
#include <stdint.h>
#include <Nano100Series.h>
#include "sys.h"
#include "gpio.h"
#include "I2Cdev.h"
#include "MPU6500.h"

void MPU6500_WriteByte(uint8_t MPU6500_reg, uint8_t MPU6500_data)
{
	uint8_t data[1];
	   data[0]=MPU6500_data;
     I2C_writeBytes(MPU6500_I2C_PORT, MPU6500_I2C_SLA, MPU6500_reg, 1, data);
}

uint8_t MPU6500_ReadByte(uint8_t MPU6500_reg)
{
	uint8_t data[1];
     I2C_readBytes(MPU6500_I2C_PORT, MPU6500_I2C_SLA, MPU6500_reg, 1, data);	
	   return (data[0]);
}

void Init_MPU6500(void)
{
	MPU6500_WriteByte(MPU6500_PWR_MGMT_1, 0x00);	// CLL_SEL=0: internal 8MHz, TEMP_DIS=0, SLEEP=0 
	MPU6500_WriteByte(MPU6500_SMPLRT_DIV, 0x07);  // Gyro output sample rate = Gyro Output Rate/(1+SMPLRT_DIV)
	MPU6500_WriteByte(MPU6500_CONFIG, 0x06);      // set TEMP_OUT_L, DLPF=2 (Fs=1KHz)
	MPU6500_WriteByte(MPU6500_GYRO_CONFIG, 0x18); // bit[4:3] 0=+-250d/s,1=+-500d/s,2=+-1000d/s,3=+-2000d/s
	MPU6500_WriteByte(MPU6500_ACCEL_CONFIG, 0x01);// bit[4:3] 0=+-2g,1=+-4g,2=+-8g,3=+-16g, ACC_HPF=On (5Hz)
}

int16_t Read_MPU6500_AccX(void)
{
	uint8_t LoByte, HiByte;
	LoByte = MPU6500_ReadByte(MPU6500_ACCEL_XOUT_L); // read Accelerometer X_Low  value
	HiByte = MPU6500_ReadByte(MPU6500_ACCEL_XOUT_H); // read Accelerometer X_High value
	return((HiByte<<8) | LoByte);
}

int16_t Read_MPU6500_AccY(void)
{
	uint8_t LoByte, HiByte;
	LoByte = MPU6500_ReadByte(MPU6500_ACCEL_YOUT_L); // read Accelerometer X_Low  value
	HiByte = MPU6500_ReadByte(MPU6500_ACCEL_YOUT_H); // read Accelerometer X_High value
	return ((HiByte<<8) | LoByte);
}

int16_t Read_MPU6500_AccZ(void)
{
	uint8_t LoByte, HiByte;
	LoByte = MPU6500_ReadByte(MPU6500_ACCEL_ZOUT_L); // read Accelerometer X_Low  value
	HiByte = MPU6500_ReadByte(MPU6500_ACCEL_ZOUT_H); // read Accelerometer X_High value
	return ((HiByte<<8) | LoByte);
}

int16_t Read_MPU6500_GyroX(void)
{
	uint8_t LoByte, HiByte;
	LoByte = MPU6500_ReadByte(MPU6500_GYRO_XOUT_L); // read Accelerometer X_Low  value
	HiByte = MPU6500_ReadByte(MPU6500_GYRO_XOUT_H); // read Accelerometer X_High value
	return ((HiByte<<8) | LoByte);
}

int16_t Read_MPU6500_GyroY(void)
{
	uint8_t LoByte, HiByte;
	LoByte = MPU6500_ReadByte(MPU6500_GYRO_YOUT_L); // read Accelerometer X_Low  value
	HiByte = MPU6500_ReadByte(MPU6500_GYRO_YOUT_H); // read Accelerometer X_High value
	return ((HiByte<<8) | LoByte);
}

int16_t Read_MPU6500_GyroZ(void)
{
	uint8_t LoByte, HiByte;
	LoByte = MPU6500_ReadByte(MPU6500_GYRO_ZOUT_L); // read Accelerometer X_Low  value
	HiByte = MPU6500_ReadByte(MPU6500_GYRO_ZOUT_H); // read Accelerometer X_High value
	return ((HiByte<<8) | LoByte);
}

uint16_t Read_MPU6500_ID(void)
{
	return (MPU6500_ReadByte(MPU6500_WHO_AM_I));
}
