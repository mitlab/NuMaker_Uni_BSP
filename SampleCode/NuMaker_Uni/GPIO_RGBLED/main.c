//
// GPIO_RGBLED : GPIOs control RGB LED
//
// EVB : NuMaker Uni
// MCU : NANO100NE3BN
// LED : RGB-LED

// On-board connections
// PB10: control Blue  LED (0=on, 1=off)
// PB11: control Red   LED (0=on, 1=off)
// PE5 : control Green LED (0=on, 1=off)

#include <stdio.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"

void Init_RGBLED(void)
{
	  GPIO_SetMode(PB, BIT10, GPIO_PMD_OUTPUT); 
	  GPIO_SetMode(PB, BIT11, GPIO_PMD_OUTPUT); 
	  GPIO_SetMode(PE, BIT5 , GPIO_PMD_OUTPUT); 	
	  PB10=1;
	  PB11=1;
	  PE5 =1;
}

int32_t main()
{	
    SYS_Init();
    Init_RGBLED();

    while(1) {
      PB10=0; // Blue
      CLK_SysTickDelay(200000);
      PB10=1; 
      CLK_SysTickDelay(200000);		
			
      PB11=0; // Red
      CLK_SysTickDelay(200000);
      PB11=1; 
      CLK_SysTickDelay(200000);			

      PE5 =0; // Green
      CLK_SysTickDelay(200000);
      PE5 =1; 
      CLK_SysTickDelay(200000);				
    }
}
