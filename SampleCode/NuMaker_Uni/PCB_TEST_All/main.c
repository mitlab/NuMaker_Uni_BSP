//
// PCB_TEST_All : Testing All components and socket pins on PCB and report on LED
//
// EVB : NuMaker Uni
// MCU : NANO100NE3BN

// On-board connections
// PB10: control Blue  LED (0=on, 1=off)
// PB11: control Red   LED (0=on, 1=off)
// PE5 : control Green LED (0=on, 1=off)

// JP2 : I2C0-SCL/PA9 , I2C0-SDA/PA8
//(I2C)  connect JP2-pin3 to JP2-pin4

// JP5 : UART0-TX/PB1, UART0-RX/PB0  & UART1-RX/PB4, UART1-TX/PB5
//       not tested by GPIO due to BT/WiFi module are driving

// JP6 : ADC2/PA2, ADC1/PA1
//(ADC)  connect JP6-pin1 to JP6-pin2

// JP7 : PA6, PA3
//(IR)   connect JP7-pin2 to JP7-pin3

// JP8 : PA15, PA14, PA13, PA12 
//(PWM)  connect JP8-pin1 to JP8-pin2, JP8-pin3 to JP8-pin4

// J2  : PB3, PC0, PC1, PC3, PC2, PB2 
//(SPI)  connect J2-pin3 to J2-pin4, J2-pin5 to J2-pin6, J2-pin7 to J2-pin8

#include <stdio.h>
#include <string.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "BLE_BT2710.h"
#include "HTU21D.h"

#define AT_END    "\r\n"
#define AT_CMD    "AT"

volatile char Text[16];
volatile uint8_t RX_buffer[13];
volatile char BT_CMD[13] = {'i','t','c','z',0,0,0,4,'T','E','S','T',0xc0};

volatile uint8_t Pass[20];
volatile uint8_t UART0_Flag=0;
volatile uint8_t UART1_Flag=0;

volatile char Text[16];

void Init_RGBLED(void)
{
	  GPIO_SetMode(PB, BIT10, GPIO_PMD_OUTPUT); 
	  GPIO_SetMode(PB, BIT11, GPIO_PMD_OUTPUT); 
	  GPIO_SetMode(PE, BIT5 , GPIO_PMD_OUTPUT); 	
	  PB10=1;
	  PB11=1;
	  PE5 =1;
}

void LED_BLUE(void) { PB10=0; } // Start Testing

void LED_RED(void)  { PB11=0; } // Test Fail

void LED_GREEN(void){	PE5=0; }  // Test Pass


void UART0_IRQHandler(void)
{
  uint32_t u32IntSts= UART0->ISR;
    
    if(u32IntSts & UART_IS_RX_READY(UART0)) {			
      UART_Read(UART0, (uint8_t*)RX_buffer, 11);
			if (RX_buffer[9]==1) Pass[17]=1;
	    else                 Pass[17]=0;
    }
		UART0_Flag=1;
}

void UART1_IRQHandler(void)
{
	  uint8_t  in_char;
    uint32_t u32IntSts= UART1->ISR;
    
    if(u32IntSts & UART_IS_RX_READY(UART1)) {	
			   UART_Read(UART1, (uint8_t*)RX_buffer, 10);		
		     if ((RX_buffer[7]=='O') && (RX_buffer[8]=='K')) Pass[18]=1;		
		     else                                            Pass[18]=0;	
    }
		UART1_Flag=1;
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
	   while(UART0_Flag==0){};	
}

void Init_WiFi(void)
{
     UART_Open(UART1,115200);
     UART_ENABLE_INT(UART1, UART_IER_RDA_IE_Msk);
     NVIC_EnableIRQ(UART1_IRQn);
}

int32_t main()
{	
	uint8_t i;
	uint8_t PassTest =1;
  char AT_cmd[4];	
	uint8_t reg;
	float   humidity;
	
    SYS_Init();
	  Init_RGBLED();
	  Init_BLE();
	  Init_WiFi();
    I2C_Open(I2C1, I2C1_CLOCK_FREQUENCY); // max.=400KHz
	
	  for (i=0; i<30; i++) Pass[i]=0;
	  CLK_SysTickDelay(1000000);		
	  LED_BLUE();

	// JP2 : I2C0-SCL/PA9 , I2C0-SDA/PA8  connect PA9 and PA8
	  GPIO_SetMode(PA, BIT9, GPIO_PMD_OUTPUT); 
	  GPIO_SetMode(PA, BIT8, GPIO_PMD_INPUT);
	  PA9=0;
	  if (PA8==0) Pass[0]=1;
	  else        Pass[0]=0;
	
	  GPIO_SetMode(PA, BIT9, GPIO_PMD_INPUT); 
	  GPIO_SetMode(PA, BIT8, GPIO_PMD_OUTPUT);
	  PA8=0;
	  if (PA9==0) Pass[1]=1;
	  else        Pass[1]=0;
		
	// JP6 : ADC2/PA2, ADC1/PA1
	  GPIO_SetMode(PA, BIT2, GPIO_PMD_OUTPUT); 
	  GPIO_SetMode(PA, BIT1, GPIO_PMD_INPUT);
	  PA2=0;
	  if (PA1==0) Pass[2]=1;
	  else        Pass[2]=0;
	
	  GPIO_SetMode(PA, BIT2, GPIO_PMD_INPUT); 
	  GPIO_SetMode(PA, BIT1, GPIO_PMD_OUTPUT);
	  PA1=0;
	  if (PA2==0) Pass[3]=1;
	  else        Pass[3]=0;
		
	// JP7 : PA6, PA3
	  GPIO_SetMode(PA, BIT6, GPIO_PMD_OUTPUT); 
	  GPIO_SetMode(PA, BIT3, GPIO_PMD_INPUT);
	  PA6=0;
	  if (PA3==0) Pass[4]=1;
	  else        Pass[4]=0;
	
	  GPIO_SetMode(PA, BIT6, GPIO_PMD_INPUT); 
	  GPIO_SetMode(PA, BIT3, GPIO_PMD_OUTPUT);
	  PA3=0;
	  if (PA6==0) Pass[5]=1;
	  else        Pass[5]=0;	
		
	// JP8 : PA15, PA14, PA13, PA12
	  GPIO_SetMode(PA, BIT15, GPIO_PMD_OUTPUT); 
	  GPIO_SetMode(PA, BIT14, GPIO_PMD_INPUT);
	  PA15=0;
	  if (PA14==0) Pass[6]=1;
	  else         Pass[6]=0;
	
	  GPIO_SetMode(PA, BIT15, GPIO_PMD_INPUT); 
	  GPIO_SetMode(PA, BIT14, GPIO_PMD_OUTPUT);
	  PA14=0;
	  if (PA15==0) Pass[7]=1;
	  else         Pass[7]=0;	
		
	  GPIO_SetMode(PA, BIT13, GPIO_PMD_OUTPUT); 
	  GPIO_SetMode(PA, BIT12, GPIO_PMD_INPUT);
	  PA13=0;
	  if (PA12==0) Pass[8]=1;
	  else         Pass[8]=0;
	
	  GPIO_SetMode(PA, BIT13, GPIO_PMD_INPUT); 
	  GPIO_SetMode(PA, BIT12, GPIO_PMD_OUTPUT);
	  PA12=0;
	  if (PA13==0) Pass[9]=1;
	  else         Pass[9]=0;
		
	// J2 : PB3, PC0, PC1, PC3, PC2, PB2
	  GPIO_SetMode(PB, BIT3, GPIO_PMD_OUTPUT); 
	  GPIO_SetMode(PC, BIT0, GPIO_PMD_INPUT);
	  PB3=0;
	  if (PC0==0) Pass[10]=1;
	  else        Pass[10]=0;
	
	  GPIO_SetMode(PB, BIT3, GPIO_PMD_INPUT); 
	  GPIO_SetMode(PC, BIT0, GPIO_PMD_OUTPUT);
	  PC0=0;
	  if (PB3==0) Pass[11]=1;
	  else        Pass[11]=0;	
		
	  GPIO_SetMode(PC, BIT1, GPIO_PMD_OUTPUT); 
	  GPIO_SetMode(PC, BIT3, GPIO_PMD_INPUT);
	  PC1=0;
	  if (PC3==0) Pass[12]=1;
	  else        Pass[12]=0;
	
	  GPIO_SetMode(PC, BIT1, GPIO_PMD_INPUT); 
	  GPIO_SetMode(PC, BIT3, GPIO_PMD_OUTPUT);
	  PC3=0;
	  if (PC1==0) Pass[13]=1;
	  else        Pass[13]=0;		

	  GPIO_SetMode(PC, BIT2, GPIO_PMD_OUTPUT); 
	  GPIO_SetMode(PB, BIT2, GPIO_PMD_INPUT);
	  PC2=0;
	  if (PB2==0) Pass[14]=1;
	  else        Pass[14]=0;
	
	  GPIO_SetMode(PC, BIT2, GPIO_PMD_INPUT); 
	  GPIO_SetMode(PB, BIT2, GPIO_PMD_OUTPUT);
	  PB2=0;
	  if (PC2==0) Pass[15]=1;
	  else        Pass[15]=0;	

		// Test HTU21D			
    reg   = HTU21D_Init();
		humidity = HTU21D_Humidity();
		if (humidity>10) Pass[16]=1;
		else             Pass[16]=0;
		
		// BLE Test
		BLE_Test();
		
    //WiFi Test
    strcpy(AT_cmd,AT_CMD);
    strcat(AT_cmd,AT_END);
    UART_Write(UART1, AT_cmd, strlen(AT_cmd));	
	  while(UART1_Flag==0){ };
		
    for (i=2; i<19; i++) {
      if (Pass[i]==0) PassTest=0; 
    }
		if (PassTest==1) LED_GREEN();
		else             LED_RED();
		
		while(1);			
}
