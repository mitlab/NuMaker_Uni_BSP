//
// proj_BT_Remote : Bluetooth to receive Button command, and transmitting IR NEC code
//                  IR receiver VS1838B receiving and display the code
//
// NuMaker_Uni_BT_Remote.aia is AI2 app project that can be imported to ai2.Appinventor2.mit.edu
// and generate a NuMaker_Uni_BT_Remote.apk
// please run this app, and scan ITON DM bluetooth device, then connect it in the App.
// Pressing the button will send text to MCU, MCU will detect the text, and transmit the IR code
// and IR receiver VS1838B can receive and display the IR code.
// 
// EVB : NuMaker Uni
// MCU : NANO100NE3BN
// BLE : ITON_DM BT2710
// IRrx: VS1838B

// UART0 to Bluetooth module
// PB0/UART0-RX to BT2710's TX
// PB1/UART0-TX to BT2710's RX

// PWM connection
// PA12/ PWM0_CH0 to IR Emitter (PWM output 38KHz)
// PA13 /PWM0_CH1 to IR Receiver (VS1838B)
//
#include <stdio.h>
#include <string.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "BLE_BT2710.h"
#include "IrDA_NEC.h"

volatile char Text[16];
volatile char RX_data[5];
volatile uint8_t BT_flag =0;

void UART0_IRQHandler(void)
{
    uint32_t u32IntSts= UART0->ISR;
    
    if(u32IntSts & UART_IS_RX_READY(UART0)) {			
			if(u32IntSts & UART_IS_RX_READY(UART0)) {
				 UART_Read(UART0, (uint8_t*)RX_data, 5);
				 printf("%s : ", RX_data);
				 BT_flag=1;
			}
    }
}

void Init_UART0(void)
{
    UART_Open(UART0, 115200);	// enable UART0 at 115200 baudrate
    UART_ENABLE_INT(UART0, UART_IER_RDA_IE_Msk);
    NVIC_EnableIRQ(UART0_IRQn);	
}

void PWM0_IRQHandler(void)
{
    uint32_t TDR_tmp;
    TDR_tmp = MaxValue - PWM_GET_CAPTURE_FALLING_DATA(PWM0, 1);
    PWM_ClearCaptureIntFlag(PWM0, 1, PWM_FALLING_LATCH_INT_FLAG);
    IrDA_NEC_Rx(TDR_tmp);
}

int32_t main (void)
{
    uint8_t au8IR_Code[4];

    SYS_Init();
    Init_UART0();
    IrDA_NEC_TxRx_Init();
	  printf("<<< proj_BT_Remote >>>\n");
	
    while(1)
    {
			if (BT_flag==1) {
				au8IR_Code[0] = 0x00;
				au8IR_Code[1] = ~au8IR_Code[0];
				au8IR_Code[2] = 0x00;
				if (RX_data[3]=='0') au8IR_Code[2] = au8IR_Code[2] + 0x00;
				if (RX_data[3]=='1') au8IR_Code[2] = au8IR_Code[2] + 0x10;
				
				if (RX_data[4]=='1') au8IR_Code[2] = au8IR_Code[2] + 0x01;
				if (RX_data[4]=='2') au8IR_Code[2] = au8IR_Code[2] + 0x02;
				if (RX_data[4]=='3') au8IR_Code[2] = au8IR_Code[2] + 0x03;
				if (RX_data[4]=='4') au8IR_Code[2] = au8IR_Code[2] + 0x04;
				if (RX_data[4]=='5') au8IR_Code[2] = au8IR_Code[2] + 0x05;
				if (RX_data[4]=='6') au8IR_Code[2] = au8IR_Code[2] + 0x06;
				if (RX_data[4]=='7') au8IR_Code[2] = au8IR_Code[2] + 0x07;
				if (RX_data[4]=='8') au8IR_Code[2] = au8IR_Code[2] + 0x08;
				if (RX_data[4]=='9') au8IR_Code[2] = au8IR_Code[2] + 0x09;
				au8IR_Code[3] = ~au8IR_Code[2];
				SendNEC(au8IR_Code);
        CLK_SysTickDelay(300000);
				BT_flag=0;
			}
    }
}
