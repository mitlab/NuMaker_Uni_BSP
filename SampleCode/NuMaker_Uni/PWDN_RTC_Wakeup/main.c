//
// PWDN_RTC_Wakeup : RTC Time to wakeup MCU from power-down mode
//
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

volatile char Text[16];
volatile S_RTC_TIME_DATA_T sCurTime;	

void RTC_IRQHandler(void)
{  			
	  Leave_PowerDown();
		print_Line(3,"Power Up !!! ");	
    // Get the current time to printf
    RTC_GetDateAndTime((S_RTC_TIME_DATA_T*)&sCurTime); 
	  sprintf((char*)Text,"Date %4d/%2d/%2d", sCurTime.u32Year,sCurTime.u32Month,sCurTime.u32Day);
    print_Line(1,(char*)Text);
	  sprintf((char*)Text,"Time %2d:%2d:%2d",	sCurTime.u32Hour,sCurTime.u32Minute,sCurTime.u32Second);
	  print_Line(2,(char*)Text);	
	
    RTC_CLEAR_TICK_INT_FLAG();	
}

void Delay(uint32_t ucnt)
{
    volatile uint32_t i = ucnt;
    while (i--);
}

void Init_RTC(void)
{
	S_RTC_TIME_DATA_T sInitTime;
    // Time Setting
    sInitTime.u32Year       = 2016;
    sInitTime.u32Month      = 1;
    sInitTime.u32Day        = 24;
    sInitTime.u32Hour       = 15;
    sInitTime.u32Minute     = 20;
    sInitTime.u32Second     = 0;
    sInitTime.u32DayOfWeek  = RTC_TUESDAY;
    sInitTime.u32TimeScale  = RTC_CLOCK_24;

    RTC_Open(&sInitTime);
    RTC_SetTickPeriod(RTC_TICK_1_SEC);
    // Enable RTC Tick Interrupt
    RTC_EnableInt(RTC_RIER_TIER_Msk);
    NVIC_EnableIRQ(RTC_IRQn);	
	  // Enable RTC wakeup
		RTC_ENABLE_TICK_WAKEUP(); 
}

int32_t main(void)
{
    SYS_Init();
	
	  I2C_Open(I2C0, I2C0_CLOCK_FREQUENCY);	
	  init_LCD();
	  clear_LCD();
	  print_Line(0,"RTC Wakeup test");

	  Init_RTC();
	
    while(1) {
		print_Line(3,"Power Down...");
		Enter_PowerDown();
		}
}
