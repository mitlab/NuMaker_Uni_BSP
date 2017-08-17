//
// RTC_LCD : display RTC Date & Time on LCD (with PowerDown)
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

void RTC_IRQHandler(void)
{
  S_RTC_TIME_DATA_T sCurTime;	
  char Text[16];
	
    Leave_PowerDown();
    // Get the current time to printf
    RTC_GetDateAndTime(&sCurTime);
	
	  print_Line(3,"Power Up-----");
    sprintf(Text,"%4d:%2d:%2d",	sCurTime.u32Year,sCurTime.u32Month,sCurTime.u32Day);
    print_Line(1, Text); // Display Date	
    sprintf(Text,"  %2d:%2d:%2d",	sCurTime.u32Hour,sCurTime.u32Minute,sCurTime.u32Second);
    print_Line(2, Text); // Display Time
	
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
    sInitTime.u32Month      = 03;
    sInitTime.u32Day        = 27;
    sInitTime.u32Hour       = 16;
    sInitTime.u32Minute     = 45;
    sInitTime.u32Second     = 0;
    sInitTime.u32DayOfWeek  = RTC_SUNDAY;
    sInitTime.u32TimeScale  = RTC_CLOCK_24;

    RTC_Open(&sInitTime);
    RTC_SetTickPeriod(RTC_TICK_1_SEC);
    RTC_EnableInt(RTC_RIER_TIER_Msk);
    NVIC_EnableIRQ(RTC_IRQn);		  
    RTC_ENABLE_TICK_WAKEUP(); // Enable RTC wakeup
}

int32_t main(void)
{
    SYS_Init();
	
    I2C_Open(I2C0, I2C0_CLOCK_FREQUENCY);	
    init_LCD();
    clear_LCD();
    print_Line(0, "RTC demo on LCD");

    Init_RTC();
	
    while(1) {
			 print_Line(3,"Power Down!!!");
       Enter_PowerDown();
    }	
}
