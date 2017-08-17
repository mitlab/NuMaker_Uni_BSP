//
// TMR1_LED : Timer1 to turn LED on/off 
//
// EVB : NuMaker Uni
// MCU : NANO100NE3BN
// LED : RGB-LED

#include <stdio.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"

volatile uint8_t ledState =0;

void TMR1_IRQHandler(void)
{	
	ledState = ~ledState;  // changing ON/OFF state
	
	TIMER_ClearIntFlag(TIMER1); // Clear Timer1 time-out interrupt flag
}

void Init_Timer1(void)
{    
    TIMER_Open(TIMER1, TMR1_OPERATING_MODE, TMR1_OPERATING_FREQ);
    TIMER_EnableInt(TIMER1);
    NVIC_EnableIRQ(TMR1_IRQn);
    TIMER_Start(TIMER1);
}

void Init_RGBLED(void)
{
	  GPIO_SetMode(PB, BIT10, GPIO_MODE_OUTPUT); 
	  GPIO_SetMode(PB, BIT11, GPIO_MODE_OUTPUT); 
	  GPIO_SetMode(PE, BIT5 , GPIO_MODE_OUTPUT); 	
	  PB10=1; // Blue
	  PB11=1; // Red
	  PE5 =1; // Green
}

int32_t main()
{	
    SYS_Init();	
    Init_Timer1();
    Init_RGBLED();

    while(1) {
      if (ledState==0) { PB10 =0; PB11 =0; PE5 =0; }
      else             { PB10 =1; PB11 =1; PE5 =1; }
    }
}
