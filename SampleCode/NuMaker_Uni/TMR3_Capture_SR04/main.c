//
// TMR3_Capture_SR04 : Timer3 Capture Ultrasonic Sensor Ranger
//
// EVB : NuMaker Uni
// MCU : NANO100NE3BN
// Sensor: HC-SR04

// JP7 connections (to HC-SR04)
// pin1 GND  : Gnd
// pin2 ECHO : PA6/TC3
// pin3 TRIG : PA3
// pin4 +5V  : VBAT connected to +5V

#include <stdio.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"

uint8_t  Timer_flag =0;
uint32_t Timer_count =0;

void TMR3_IRQHandler(void)
{
    Timer_count = TIMER_GetCaptureData(TIMER3);
    Timer_flag =1;
    TIMER_ClearCaptureIntFlag(TIMER3);
}

void Init_TimerCapture(void)
{
    TIMER_Open(TIMER3, TMR3_OPERATING_MODE, TMR3_OPERATING_FREQ);
    TIMER_SET_PRESCALE_VALUE(TIMER3, 11); //
    // Set compare value as large as possible, so don't need to worry about counter overrun too frequently.
    TIMER_SET_CMP_VALUE(TIMER3, 0xFFFFFF);	
    TIMER_EnableCapture(TIMER3, TMR3_CAPTURE_MODE, TMR3_CAPTURE_EDGE);	
    TIMER_EnableCaptureInt(TIMER3); // Enable timer interrupt
    NVIC_EnableIRQ(TMR3_IRQn);
    TIMER_Start(TIMER3);	
}

int main(void)
{
    float distance;
	
    SYS_Init();
	
    printf("Timer3 Capturing SR04\n");
    GPIO_SetMode(PA, BIT3, GPIO_MODE_OUTPUT);
    PA3=0;
	
    Init_TimerCapture();	
	  
    while(1) {
       PA3=1;
       CLK_SysTickDelay(10);
       PA3=0;
       CLK_SysTickDelay(40000);
			
       if (Timer_flag==1) {      
          TIMER_Stop(TIMER3);	
          distance = Timer_count * 340 /20000;
          printf("Time= %d, Distance= %d cm\n", Timer_count, (int) distance);
          Timer_flag=0;
          TIMER_Start(TIMER3);
       }				
    }
}
