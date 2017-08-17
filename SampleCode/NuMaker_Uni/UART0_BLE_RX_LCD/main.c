//
// UART0_BT_RX_LCD : Bluetooth Receive & display on LCD
//
// EVB : NuMaker Uni
// MCU : NANO100NE3BN
// BLE : ITON_DM BT2710

// UART0 to Bluetooth module
// PB0/UART0-RX to BT2710's TX
// PB1/UART0-TX to BT2710's RX

// JP2 connections (I2C0 to LCD)
// PA9/I2C0-SCL to LCD's SCL
// PA8/I2C0-SDA to LCD's SDA

#include <stdio.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "BLE_BT2710.h"
#include "I2C_SSD1306Z.h"

volatile char Text[16];
volatile char RX_data;
volatile uint8_t line =1;
volatile uint8_t col=0;

void UART0_IRQHandler(void)
{
    uint32_t u32IntSts= UART0->ISR;
    
    if(u32IntSts & UART_IS_RX_READY(UART0)) {			
			while(!UART_GET_RX_EMPTY(UART0)) {
				 RX_data = UART_READ(UART0);				
				 print_C(line, col, RX_data);
				 col++;
				 if (col>15) { col=0; line++; }
				 if (line>3) line=0;
			}			
    }
}

void Init_UART0(void)
{
    UART_Open(UART0, 9600);	// enable UART0 at 9600 baudrate
    UART_ENABLE_INT(UART0, UART_IER_RDA_IE_Msk);
    NVIC_EnableIRQ(UART0_IRQn);	
}

int32_t main()
{
    SYS_Init();
    Init_UART0();

    I2C_Open(I2C0, I2C0_CLOCK_FREQUENCY);
    init_LCD();
    clear_LCD();
	
    print_Line(0,"BT-BLE Receiving");

    while(1) {
    }
}
