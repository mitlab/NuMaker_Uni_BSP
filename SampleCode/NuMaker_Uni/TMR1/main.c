//
// TMR1 : Timer1 counting
//
// EVB : NuMaker Uni
// MCU : NANO10NE3BN

#include <stdio.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"

volatile uint32_t timer_count =0;

void TMR1_IRQHandler(void)
{
    timer_count++;
    printf("Timer1 = %d\n", timer_count);

    TIMER_ClearIntFlag(TIMER1);  // clear timer interrupt flag
}

void Init_Timer1(void)
{    
    TIMER_Open(TIMER1, TMR1_OPERATING_MODE, TMR1_OPERATING_FREQ);
    TIMER_EnableInt(TIMER1);
    NVIC_EnableIRQ(TMR1_IRQn);
    TIMER_Start(TIMER1);
}

int32_t main()
{	
    SYS_Init();	
    Init_Timer1();

    while(1) {
    }
}
