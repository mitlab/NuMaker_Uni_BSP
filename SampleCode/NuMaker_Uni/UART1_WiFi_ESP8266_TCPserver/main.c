//
// UART1_WiFi_ESP8266_TCPserver : ESP8266 run as a TCP server
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

#define AT_QUO    "\""
#define AT_COMMA  ","
#define AT_END    "\r\n"
#define AT_CMD    "AT"
#define AT_RST    "AT+RST"
#define AT_CWMODE "AT+CWMODE=3"
#define AT_CWJAP  "AT+CWJAP=\"ittraining401\",\"itstudent\""
#define AT_CIPMUX "AT+CIPMUX=1"
#define AT_CIPSERVER "AT+CIPSERVER=1,8080"
#define AT_CIFSR  "AT+CIFSR"

volatile char Text[16];

void UART1_IRQHandler(void)
{
	  uint8_t  in_char;
    uint32_t u32IntSts= UART1->ISR;
    
    if(u32IntSts & UART_IS_RX_READY(UART1)) {		
				 in_char = UART_READ(UART1);				
			   printf("%c", in_char);
    }
}

void Init_UART(void)
{
     UART_Open(UART0,115200);	
     UART_Open(UART1,115200);
     UART_ENABLE_INT(UART1, UART_IER_RDA_IE_Msk);
     NVIC_EnableIRQ(UART1_IRQn);
}

void Init_WiFi(void)
{
    uint8_t i;
    char AT_cmd[48];
    // AT
    strcpy(AT_cmd,AT_CMD);
    strcat(AT_cmd,AT_END);	
    UART_Write(UART1, AT_cmd, strlen(AT_cmd));
    CLK_SysTickDelay(1000000);
    // AT+CWMODE=1
    strcpy(AT_cmd,AT_CWMODE);
    strcat(AT_cmd,AT_END);	
    UART_Write(UART1, AT_cmd,strlen(AT_cmd));
    CLK_SysTickDelay(1000000);
    // AT+CWJAP="WiFi810N","0972211921"
    strcpy(AT_cmd,AT_CWJAP);
    strcat(AT_cmd,AT_END);	
    UART_Write(UART1, AT_cmd,strlen(AT_cmd));
    for (i=0; i<40; i++) CLK_SysTickDelay(1000000);
    // AT+CPIMUX=1
    strcpy(AT_cmd,AT_CIPMUX);
    strcat(AT_cmd,AT_END);	
    UART_Write(UART1, AT_cmd, strlen(AT_cmd));		
    CLK_SysTickDelay(1000000);	
    // AT+CIPSERVER=1,8088
    strcpy(AT_cmd,AT_CIPSERVER);
    strcat(AT_cmd,AT_END);
    UART_Write(UART1, AT_cmd, strlen(AT_cmd));
    for (i=0; i<10; i++) CLK_SysTickDelay(1000000);
    // AT+CIFSR
    strcpy(AT_cmd,AT_CIFSR);
    strcat(AT_cmd,AT_END);
    UART_Write(UART1, AT_cmd, strlen(AT_cmd));
    for (i=0; i<10; i++) CLK_SysTickDelay(1000000);	
    printf("TCP server up!!!\n");
}

int32_t main()
{
    SYS_Init();
    Init_UART();
	
    printf("WiFi ESP8266\n");	
	  Init_WiFi();	

    while(1) {
    }
}
