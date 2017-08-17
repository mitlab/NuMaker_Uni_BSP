//
// PWM_Music : PWM output tone to Buzzer
//             music = Fur Elise
// EVB : NuMaker Uni
// MCU : NABO100NE3BN

// JP8 : PWM connections
// PA12 /PWM0_CH0 to Buzzer (1 drive Buzzer 2400Hz)
// * PWM high width need to be shorter to avoid 2400Hz noise

#include <stdio.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "Note_Freq.h"

#define  PITCH  125000 // 125ms

  uint16_t tone[120] = {
	E6 ,D6u,E6 ,D6u,E6 ,B5 ,D6 ,C6 ,A5 ,A5 , 0 , 0 ,
	C5 ,E5 ,A5 ,B5 ,B5 , 0 ,C5 ,A5 ,B5 ,C6 ,C6 , 0 ,
	E6 ,D6u,E6 ,D6u,E6 ,B5 ,D6 ,C6 ,A5 ,A5 , 0 , 0 ,
	C5 ,E5 ,A5 ,B5 ,B5 , 0 ,E5 ,C6 ,B5 ,A5 ,A5 , 0 ,
	B5 ,C6 ,D6 ,E6 ,E6 , 0 ,G5 ,F6 ,E6 ,D6 ,D6 , 0 ,
	F5 ,E6 ,D6 ,C6 ,C6 , 0 ,E5 ,D6 ,C6 ,B5 ,B5 , 0 ,
	E6 ,D6u,E6 ,D6u,E6 ,B5 ,D6 ,C6 ,A5 ,A5 , 0 , 0 ,
	C5 ,E5 ,A5 ,B5 ,B5 , 0 ,C5 ,A5 ,B5 ,C6 ,C6 , 0 ,
	E6 ,D6u,E6 ,D6u,E6 ,B5 ,D6 ,C6 ,A5 ,A5 , 0 , 0 ,
	C5 ,E5 ,A5 ,B5 ,B5 , 0 ,E5 ,C6 ,B5 ,A5 ,A5 , 0 };
	

void Init_PWM(void) 
{
    PWM_Start(PWM0, PWM_CH_0_MASK);
}

int32_t main()
{	
	uint8_t i;
	
    SYS_Init();	
	  Init_PWM();

	  for (i=0; i<120; i++) {
			PWM_ConfigOutputChannel(PWM0, PWM_CH0, tone[i], 10);
			if (tone[i]!=0) PWM_EnableOutput(PWM0, PWM_CH_0_MASK); // enable PWM0 Ch0
			else    				PWM_DisableOutput(PWM0, PWM_CH_0_MASK);// disable PWM0 Ch0
		  CLK_SysTickDelay(PITCH);
    }
}
