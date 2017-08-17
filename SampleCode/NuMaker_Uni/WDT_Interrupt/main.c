//
// WDT_Interrupt : WatchDog Timer timeout to interrupt MCU
// 
// WDT clock source = 10KHz (LIRC)
//
// EVB : NuMaker Uni
// MCU : Nano100BE3BN
// LCD : 0.96" OLED 128x64

// JP2 to LCD
// PA9/I2C0-SCL to LCD's SCL
// PA8/I2C0-SDA to LCD's SDA

#include <stdio.h>
#include <string.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "I2C_SSD1306Z.h"

volatile char Text[16];
volatile uint8_t u8WDT_Flag =0;
	
void WDT_IRQHandler(void)
{
    if(WDT_GET_TIMEOUT_INT_FLAG()) { // Check WDT interrupt flag
       u8WDT_Flag=1;			
       WDT_CLEAR_TIMEOUT_INT_FLAG(); // Clear WDT interrupt flag
		}    
}

void Init_WDT(void)
{
    // WDT timeout every 2^14 WDT clock, enable system reset, disable wake up system
    SYS_UnlockReg();
    WDT_Open(WDT_TIMEOUT_2POW14, 0, FALSE, FALSE);
    SYS_LockReg();	
    WDT_EnableInt();          // Enable WDT timeout interrupt
    NVIC_EnableIRQ(WDT_IRQn); // Enable Cortex-M0 NVIC WDT interrupt vector
}

int32_t main (void)
{
  uint32_t i=0;
	
    SYS_Init();
	
    I2C_Open(I2C0, I2C0_CLOCK_FREQUENCY);
    init_LCD();
    clear_LCD();

    print_Line(0,"WDT Timeout Test");
	
    Init_WDT();

    while(1) {
       if (u8WDT_Flag==1) {
           print_Line(2, "WDT Timeout!!!");
           u8WDT_Flag=0;
	     } else {
	         print_Line(2, "              ");
	     }
	     sprintf((char*)Text,"running..%d", i);
	     print_Line(3,(char*)Text);
	     i++;
    }
}
