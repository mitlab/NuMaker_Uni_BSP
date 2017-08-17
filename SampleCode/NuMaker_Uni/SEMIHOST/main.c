//
// SEMIHOST : using Keil MDK Debug Session
//
// EVB : NuMaker Uni
// MCU : Nano100NE3BN

#include <stdio.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"

int32_t main()
{	
    uint32_t i =0;
	
    SYS_Init();	
	
	  printf(" Keil MDK>Flash>Configure Flash Tool...>\n");
	  printf(" C/C++ Define: DEBUG_ENABLE_SEMIHOST\n");
	  printf(" Asm Define: DEBUG_ENABLE_SEMIHOST\n");

    while(1) {
			printf("%d\n", i);
			i++;
    }
}
