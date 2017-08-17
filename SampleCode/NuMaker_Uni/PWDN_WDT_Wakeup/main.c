//
// PWDN_WDT_Wakeup : WatchDog Timer timeout to wake up MCU from power-down mode
// 
// Note: No NuLink Debug Session
// 0.WDT clock source = 10KHz (LIRC)
// 1.System must enter PowerDown mode to have WakeUp
// 2.NuLink ICE connection will prevent CPU to enter PowerDown mode
//   so if want to enter powerdown, Debug Session should not be used
//   hence SEMIHOST, printf are not supported

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

volatile char Text[16];
volatile uint32_t wakeup_count =0;

void WDT_IRQHandler(void)
{
    print_Line(1,"Power Up !!! ");

    if(WDT_GET_TIMEOUT_WAKEUP_FLAG())	
       print_Line(2,"WDT WAKEUP...");
				
    sprintf((char*)Text,"WakeupCnt: %5d", wakeup_count);
       print_Line(3,(char*)Text);
       wakeup_count++;
	
    WDT_CLEAR_TIMEOUT_INT_FLAG(); // Clear WDT interrupt flag
    WDT_CLEAR_TIMEOUT_WAKEUP_FLAG(); // Clear WDT wake up flag		
}

void Init_WDT(void)
{
    // WDT timeout every 2^14 WDT clock, disable system reset, enable wake up system
    SYS_UnlockReg();
    WDT_Open(WDT_TIMEOUT_2POW14, 0, FALSE, TRUE);
    SYS_LockReg();	
    WDT_EnableInt();          // Enable WDT timeout interrupt
    NVIC_EnableIRQ(WDT_IRQn); // Enable Cortex-M0 NVIC WDT interrupt vector
}

int32_t main (void)
{
    SYS_Init();
	
    I2C_Open(I2C0, I2C0_CLOCK_FREQUENCY);
    init_LCD();
    clear_LCD();

    print_Line(0,"WDT Wakeup Test");	
	  
    Init_WDT();	

    while(1) {
       print_Line(1,"Power Down...");
       print_Line(2,"             ");
			
    // Stop Clock but pin configurations not saved
       SYS_UnlockReg();			
       CLK_PowerDown();
       SYS_LockReg();
    }
}
