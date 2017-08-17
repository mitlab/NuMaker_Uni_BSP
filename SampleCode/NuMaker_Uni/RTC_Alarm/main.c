//
// RTC_Alarm : RTC alarm in 5 second (printf to display)
//
// external 32.768KHz clock source (LXT) needed
//
// EVB : NuMaker Uni
// MCU : Nano100NE3BN

#include <stdio.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"

volatile int32_t   g_bAlarm  = FALSE;

void RTC_AlarmHandler(void)
{
    printf(" Alarm!!!\n");
    g_bAlarm = TRUE;
}

void RTC_IRQHandler(void)
{
    if ( (RTC->RIER & RTC_RIER_AIER_Msk) && (RTC->RIIR & RTC_RIIR_AIF_Msk) ) { // alarm interrupt occurred
        RTC->RIIR = 0x1;

        RTC_AlarmHandler();
    }
}

void Init_RTC(void)
{
  S_RTC_TIME_DATA_T sInitTime;

    // Time Setting
    sInitTime.u32Year       = 2015;
    sInitTime.u32Month      = 11;
    sInitTime.u32Day        = 29;
    sInitTime.u32Hour       = 9;
    sInitTime.u32Minute     = 15;
    sInitTime.u32Second     = 0;
    sInitTime.u32DayOfWeek  = RTC_SUNDAY;
    sInitTime.u32TimeScale  = RTC_CLOCK_24;

    RTC_Open(&sInitTime);
    RTC_SetTickPeriod(RTC_TICK_1_SEC);
}

int32_t main(void)
{
  S_RTC_TIME_DATA_T sCurTime;

    SYS_Init();

    Init_RTC();

    printf("RTC Alarm Test Begin...\n");
    printf("(Alarm after 5 seconds)\n\n");

    g_bAlarm = FALSE;

    // Get the current time
    RTC_GetDateAndTime(&sCurTime);

    printf(" Current Time:%d/%02d/%02d %02d:%02d:%02d\n",sCurTime.u32Year,sCurTime.u32Month,
           sCurTime.u32Day,sCurTime.u32Hour,sCurTime.u32Minute,sCurTime.u32Second);

    // The alarm time setting
    sCurTime.u32Second = sCurTime.u32Second + 5;
    
    RTC_SetAlarmDateAndTime(&sCurTime); // Set the alarm time
    RTC_EnableInt(RTC_RIER_AIER_Msk);   // Enable RTC Alarm Interrupt
    NVIC_EnableIRQ(RTC_IRQn);

    while(!g_bAlarm);

    printf(" Current Time:%d/%02d/%02d %02d:%02d:%02d\n",sCurTime.u32Year,sCurTime.u32Month,
           sCurTime.u32Day,sCurTime.u32Hour,sCurTime.u32Minute,sCurTime.u32Second);

    // Disable RTC Alarm Interrupt
    RTC_DisableInt(RTC_RIER_AIER_Msk);
    NVIC_DisableIRQ(RTC_IRQn);

    printf("\nRTC Alarm Test End...\n");
    while(1);
}
