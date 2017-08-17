//
// GPIO_IRQ : GPIO interrupt triggered by buttons
//
// EVB : NuMaker Uni
// MCU : Nano100NB3BN
// JP8 : Button Inputs

// JP8 connections
// PA15 to Button1
// PA14 to Button2
// PA13 to Button3
// PA12 is used to drive IR emitter

#include <stdio.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"

volatile uint8_t B1_Flag = 0;
volatile uint8_t B2_Flag = 0;
volatile uint8_t B3_Flag = 0;

void GPABC_IRQHandler(void)
{
    if (PA->ISRC & BIT15) { // check if PA15 interrupt occurred
        PA->ISRC |= BIT15;  // clear PA15 interrupt status
			  B1_Flag=1;          // set a flag for Button1
    }; 
		if (PA->ISRC & BIT14) { // check if PA14 interrupt occurred
        PA->ISRC |= BIT14;  // clear PA14 interrupt status  
        B2_Flag=1;	        // set a flag for Button2
    };
		if (PA->ISRC & BIT13) { // check if PA13 interrupt occurred
        PA->ISRC |= BIT13;  // clear PA13 interrupt status  
        B3_Flag=1;	        // set a flag for Button3
    };		
}

void Init_Buttons(void)
{
    GPIO_SetMode(PA, (BIT13 | BIT14 | BIT15), GPIO_PMD_INPUT);
    GPIO_ENABLE_PULL_UP(PA, (BIT13 | BIT14 | BIT15));	
    GPIO_EnableInt(PA, 15, GPIO_INT_FALLING);
    GPIO_EnableInt(PA, 14, GPIO_INT_FALLING);
  	GPIO_EnableInt(PA, 13, GPIO_INT_FALLING);			
    NVIC_EnableIRQ(GPABC_IRQn);
    GPIO_SET_DEBOUNCE_TIME(GPIO_DBCLKSRC_LIRC, GPIO_DBCLKSEL_64); // debounce clock source = HCLK or LIRC
    GPIO_ENABLE_DEBOUNCE(PA, (BIT13 | BIT14 | BIT15));	
}

int32_t main()
{	
    SYS_Init();	
	  Init_Buttons();
	  printf("Testing Button IRQ generation:\n");

    while(1) {	
			  if (B1_Flag) {
					printf("B1: PA15 Interrupt!\n");
					B1_Flag=0;
				}			
			  if (B2_Flag) {
					printf("B2: PA14 Interrupt!\n");
					B2_Flag=0;
				}
			  if (B3_Flag) {
			    printf("B3: PA13 Interrupt!\n");
					B3_Flag=0;
				}		
		}
}
