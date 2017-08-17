//
// I2C_HTU21D : read humidity & temperature
//
// EVB : NuMaker Uni
// MCU : NANO100NE3BN
// HTU21D : Digital Relative Humidity Sensor with Temperature Output

// I2C1 to HTU21D
// PA11/I2C1-SCL to IMU's SCL
// PA10/I2C1-SDA to IMU's SDA

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "HTU21D.h"	

int32_t main()
{
	  int i;
    uint8_t  reg;
    float    Humidity, Temperature;
	
    SYS_Init();	
    I2C_Open(I2C1, I2C1_CLOCK_FREQUENCY); // max.=400KHz
    printf("I2C1 to HTU21D...\n");
	
    reg   = HTU21D_Init();
    printf("user reg.=%x\n", reg);
	  
    while(1) {
      Humidity    = HTU21D_Humidity();
      Temperature = HTU21D_Temperature();			
      printf("Humidity=%f, Temperature = %f\n", Humidity, Temperature);
			for (i=0; i<10; i++) CLK_SysTickDelay(1000000);
    }
}
