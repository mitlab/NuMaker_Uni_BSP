//
// WDT_Reset : WatchDog Timer timeout to reset MCU
// 
// WDT clock source = 10KHz (LIRC)
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

void WDT_IRQHandler(void)
{
    if(WDT_GET_TIMEOUT_INT_FLAG()) { // Check WDT interrupt flag
       WDT_CLEAR_TIMEOUT_INT_FLAG(); // Clear WDT interrupt flag
		}    
    if(WDT_GET_RESET_FLAG()) { // Check WDT wake up flag
       WDT_CLEAR_RESET_FLAG(); // Clear WDT wake up flag
		}		
}

void Init_WDT(void)
{
    // WDT timeout every 2^14 WDT clock, enable system reset, disable wake up system
    SYS_UnlockReg();
    WDT_Open(WDT_TIMEOUT_2POW14, 0, TRUE, FALSE);
    SYS_LockReg();
    WDT_EnableInt();          // Enable WDT timeout interrupt
    NVIC_EnableIRQ(WDT_IRQn); // Enable Cortex-M0 NVIC WDT interrupt vector
}

int32_t main (void)
{
  char Text[16];
  uint32_t i=0;
	
    SYS_Init();
	
    I2C_Open(I2C0, I2C0_CLOCK_FREQUENCY);
    init_LCD();
    clear_LCD();

    print_Line(0,"WDT RESET Test");
	
    Init_WDT();

    while(1) {			
       sprintf(Text,"running..%d", i);
       print_Line(3,Text);
       i++;
    }
}
