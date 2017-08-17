//
// PWDN_TMR_Wakeup : Timer timeout to wakeup MCU from power-down mode
// 
// Note: No NuLink Debug Session
// 1.System must enter PowerDown mode to have WakeUp
// 2.NuLink ICE connection will prevent CPU to enter PowerDown mode
//   so printf is not supported if want to see WakeUp
// 3. PowerDown mode : Timer need to use LXT as clock source to wakeup

// EVB : NuMaker Uni
// MCU : Nano100NE3BN
// LCD : I2C OLED 128x64

// JP2 connection
// PA9/I2C0-SCL to LCD's SCL
// PA8/I2C0-SDA to LCD's SDA

#include <stdio.h>
#include <string.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "I2C_SSD1306Z.h"
#include "PowerDown.h"

volatile uint32_t timer_count =0;
volatile char Text[16];

void TMR1_IRQHandler(void)
{ 
    Leave_PowerDown();
    print_Line(1,"Wakeup Up !!!");
    timer_count++;
    sprintf((char*)Text, "WakeupCnt: %5d", timer_count);
    print_Line(2, (char*)Text);
	 
    // clear timer interrupt flag
    TIMER_ClearWakeupFlag(TIMER1);	 
    TIMER_ClearIntFlag(TIMER1);
}

void Init_Timer1(void)
{    
    TIMER_Open(TIMER1, TMR1_OPERATING_MODE, TMR1_OPERATING_FREQ);
    TIMER_EnableInt(TIMER1);
    NVIC_EnableIRQ(TMR1_IRQn);
    TIMER_EnableWakeup(TIMER1);
    TIMER_Start(TIMER1);
}

int32_t main (void)
{
    SYS_Init();
	
    I2C_Open(I2C0, I2C0_CLOCK_FREQUENCY);
    init_LCD();
    clear_LCD();
    print_Line(0,"TMR1 Wakeup Test");
	
    Init_Timer1();
	
    while(1) {
      print_Line(1,"Power Down...");
      Enter_PowerDown();
    }
}
