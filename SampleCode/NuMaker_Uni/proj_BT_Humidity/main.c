//
// proj_BT_Humidity: read humidity & temperature and transmit through bluetooth to smartphone
//
// EVB : NuMaker Uni
// MCU : 
// BLE : ITON_DM BT2710
// HTU21D : Digital Relative Humidity Sensor with Temperature Output


// UART0 to Bluetooth module
// PB0/UART0-RXD to HC-05 TXD
// PB1/UART0-TXD to HC-05 RXD

// I2C1 to HTU21D
// PA11/I2C1-SCL to IMU's SCL
// PA10/I2C1-SDA to IMU's SDA

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "BLE_BT2710.h"
#include "HTU21D.h"

volatile char Text[16];
volatile char RX_data[5];
volatile uint8_t BT_flag =0;
volatile float Humidity;
volatile float Temperature;
volatile uint8_t T_int, T_dec;
volatile uint8_t H_int, H_dec;

void UART0_IRQHandler(void)
{
    uint32_t u32IntSts= UART0->ISR;
    
    if(u32IntSts & UART_IS_RX_READY(UART0)) {			
			if(u32IntSts & UART_IS_RX_READY(UART0)) {
				 UART_Read(UART0, (uint8_t*)RX_data, 4);
				 if (RX_data[0]=='H' && RX_data[1]=='T' && RX_data[2]=='U' && RX_data[3]=='D')
				 {
					 Temperature = HTU21D_Temperature();
           Humidity    = HTU21D_Humidity();
					 T_int = (int)Temperature;
					 T_dec = Temperature - T_int;

					 H_int = (int)Humidity;
					 H_dec = Humidity - H_int;
					 
					 UART_WRITE(UART0, T_int);
					 UART_WRITE(UART0, T_dec);
					 UART_WRITE(UART0, H_int);
					 UART_WRITE(UART0, H_dec);					 
				 } 
			}
    }
}

void Init_UART0(void)
{
    UART_Open(UART0, 115200);	// enable UART0 at 115200 baudrate
    UART_ENABLE_INT(UART0, UART_IER_RDA_IE_Msk);
    NVIC_EnableIRQ(UART0_IRQn);	
}

int32_t main()
{
    int i;
    uint8_t  reg;
	
    SYS_Init();
	  Init_UART0();
    I2C_Open(I2C1, I2C1_CLOCK_FREQUENCY); // max.=400KHz	
    reg   = HTU21D_Init();
	  
    while(1) {
    }
}
