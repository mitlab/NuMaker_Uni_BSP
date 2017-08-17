//
// UART1_WiFi_TEST_LCD : Test ESP8266 AT Command OK
//
// EVB : NuMaker Uni
// MCU : NANO100NE3BN
// WiFi: ESP-03 (ESP8266)
//
// UART1 to WiFi connections
// PB4/UART1-RX to WiFi's TX 
// PB5/UART1-TX to WiFi's RX

#include <stdio.h>
#include <string.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "I2C_SSD1306Z.h"

#define AT_END    "\r\n"
#define AT_CMD    "AT"

volatile char Text[16];
volatile char RX_buffer[10];

void UART1_IRQHandler(void)
{
    uint8_t  in_char;
    uint32_t u32IntSts= UART1->ISR;
    
    if(u32IntSts & UART_IS_RX_READY(UART1)) {	
			   UART_Read(UART1, (uint8_t*)RX_buffer, 10);
			   sprintf((char*)Text,"%s",RX_buffer);
			   print_Line(1,(char*)Text);
			   print_C(2,0, RX_buffer[7]);
			   print_C(2,1, RX_buffer[8]);
    }
}

void Init_WiFi(void)
{
     UART_Open(UART1,115200);
     UART_ENABLE_INT(UART1, UART_IER_RDA_IE_Msk);
     NVIC_EnableIRQ(UART1_IRQn);
}

void WiFi_Test(void)
{
    char AT_cmd[48];
    // AT
    strcpy(AT_cmd,AT_CMD);
    strcat(AT_cmd,AT_END);	
    UART_Write(UART1, AT_cmd, strlen(AT_cmd));
    CLK_SysTickDelay(1000000);
}

int32_t main()
{
    SYS_Init();
    Init_WiFi();
    I2C_Open(I2C0, I2C0_CLOCK_FREQUENCY);
    init_LCD();
    clear_LCD();
	
    print_Line(0,"WiFi ESP8266");	
	  WiFi_Test();	

    while(1) {
    }
}
