//
// UART0_BLE_TEST_LCD : BLE Device Test Command with LCD
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
#include <string.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "BLE_BT2710.h"
#include "I2C_SSD1306Z.h"

#define CMD_TYPE      "itcz"
#define ACK_TYPE      "itaz"
#define PACKET_DATA   "TEST"

volatile char Text[16];
volatile uint8_t RX_buffer[13];

volatile char BT_CMD[13] = {'i','t','c','z',0,0,0,4,'T','E','S','T',0xc0};
volatile char RSP_FOR_CMD;
volatile uint8_t ptr = 0;


void UART0_IRQHandler(void)
{ 
	uint8_t in_char;
  uint32_t u32IntSts= UART0->ISR;
    
    if(u32IntSts & UART_IS_RX_READY(UART0)) {
			in_char = UART_READ(UART0);
			RX_buffer[ptr] = in_char;
			if(in_char==0) in_char=0x30;
			if(in_char==1) in_char=0x31;			
			print_C(1,ptr,in_char);
			ptr++;

			if (ptr==10) {
			  if (RX_buffer[9]==1) print_Line(3, "TEST_PASS");
		    else                 print_Line(3, "TEST_FAIL");
			}
    }
}

void Init_BLE(void)
{
    UART_Open(UART0, 115200);	// enable UART0 at 115200 baudrate
    UART_ENABLE_INT(UART0, UART_IER_RDA_IE_Msk);
    NVIC_EnableIRQ(UART0_IRQn);	
}

void BLE_Test()
{	
  UART_Write(UART0, (uint8_t*)BT_CMD, 13);
}

int32_t main()
{
    SYS_Init();
    Init_BLE();
    I2C_Open(I2C0, I2C0_CLOCK_FREQUENCY);
    init_LCD();
    clear_LCD();	

    print_Line(0,"BLE CMD TEST");
    BLE_Test();

    while(1) {
    }
}
