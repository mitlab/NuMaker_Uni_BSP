//
// Nano102
//
#include <stdio.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"

void SYS_Init(void)
{
    SYS_UnlockReg(); // Unlock protected registers

	  // select Chip clock source & set clock source
    CLK_EnableXtalRC(MCU_CLOCK_SOURCE_MASK);    // Enable HXT external 12MHz crystal
    CLK_WaitClockReady(MCU_CLOCK_STABLE_MASK);	
    CLK_SetCoreClock(MCU_CLOCK_FREQUENCY);      // Set HCLK clock to 32MHz

    // Select IP clock source & enable module
	  #ifdef MCU_INTERFACE_GPIO
    CLK_EnableModuleClock(GPIO_MODULE);	
    CLK_SetModuleClock(GPIO_MODULE, 0, 0);	
	  #endif
	
	  #ifdef MCU_INTERFACE_DMA
    CLK_EnableModuleClock(DMA_MODULE);	
    CLK_SetModuleClock(DMA_MODULE, 0, 0);	
	  #endif
	
	  #ifdef MCU_INTERFACE_ISP
    CLK_EnableModuleClock(ISP_MODULE);	
    CLK_SetModuleClock(ISP_MODULE, 0, 0);	
	  #endif

	  #ifdef MCU_INTERFACE_EBI
    CLK_EnableModuleClock(EBI_MODULE);	
    CLK_SetModuleClock(EBI_MODULE, 0, 0);	
	  #endif

	  #ifdef MCU_INTERFACE_SRAM
    CLK_EnableModuleClock(SRAM_MODULE);	
    CLK_SetModuleClock(SRAM_MODULE, 0, 0);	
	  #endif

	  #ifdef MCU_INTERFACE_TICK
    CLK_EnableModuleClock(TICK_MODULE);	
    CLK_SetModuleClock(TICK_MODULE, 0, 0);	
	  #endif
		
	  #ifdef MCU_INTERFACE_RTC
    CLK_EnableModuleClock(RTC_MODULE);	
    CLK_SetModuleClock(RTC_MODULE, 0, 0);	
	  #endif
	
	  #ifdef MCU_INTERFACE_WDT
    CLK_EnableModuleClock(WDT_MODULE);	
    CLK_SetModuleClock(WDT_MODULE, 0, 0);
	  #endif

	  #ifdef MCU_INTERFACE_USB
    CLK_EnableModuleClock(USBD_MODULE);	
    CLK_SetModuleClock(USBD_MODULE, 0, CLK_USB_CLK_DIVIDER(USB_CLOCK_DIVIDER));
    #endif
		
	  #ifdef MCU_INTERFACE_TMR0
       CLK_EnableModuleClock(TMR0_MODULE);	
	     #ifdef TMR0_CLOCK_SOURCE_HXT
			 CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_HXT, 0);
			 #endif
	     #ifdef TMR0_CLOCK_SOURCE_LXT
			 CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_LXT, 0);
			 #endif	
			 #ifdef TMR0_CLOCK_SOURCE_LIRC
			 CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_LIRC, 0);
			 #endif
			 #ifdef TMR0_CLOCK_SOURCE_EXT
			 CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_EXT, 0);
			 #endif
			 #ifdef TMR0_CLOCK_SOURCE_HIRC
			 CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_HIRC, 0);
			 #endif		
	  #endif
	
	  #ifdef MCU_INTERFACE_TMR1
       CLK_EnableModuleClock(TMR1_MODULE);	
	     #ifdef TMR1_CLOCK_SOURCE_HXT
			 CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1_S_HXT, 0);
			 #endif
	     #ifdef TMR1_CLOCK_SOURCE_LXT
			 CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1_S_LXT, 0);
			 #endif	
			 #ifdef TMR1_CLOCK_SOURCE_LIRC
			 CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1_S_LIRC, 0);
			 #endif
			 #ifdef TMR1_CLOCK_SOURCE_EXT
			 CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1_S_EXT, 0);
			 #endif
			 #ifdef TMR1_CLOCK_SOURCE_HIRC
			 CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1_S_HIRC, 0);
			 #endif					
	  #endif

	  #ifdef MCU_INTERFACE_TMR2
       CLK_EnableModuleClock(TMR2_MODULE);	
	     #ifdef TMR2_CLOCK_SOURCE_HXT
			 CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL2_TMR2_S_HXT, 0);
			 #endif
	     #ifdef TMR2_CLOCK_SOURCE_LXT
			 CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL2_TMR2_S_LXT, 0);
			 #endif	
			 #ifdef TMR2_CLOCK_SOURCE_LIRC
			 CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL2_TMR2_S_LIRC, 0);
			 #endif
			 #ifdef TMR2_CLOCK_SOURCE_EXT
			 CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL2_TMR2_S_EXT, 0);
			 #endif
			 #ifdef TMR2_CLOCK_SOURCE_HIRC
			 CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL2_TMR2_S_HIRC, 0);
			 #endif			
	  #endif

	  #ifdef MCU_INTERFACE_TMR3
       CLK_EnableModuleClock(TMR3_MODULE);	
	     #ifdef TMR3_CLOCK_SOURCE_HXT
			 CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL2_TMR3_S_HXT, 0);
			 #endif
	     #ifdef TMR3_CLOCK_SOURCE_LXT
			 CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL2_TMR3_S_LXT, 0);
			 #endif	
			 #ifdef TMR3_CLOCK_SOURCE_LIRC
			 CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL2_TMR3_S_LIRC, 0);
			 #endif
			 #ifdef TMR3_CLOCK_SOURCE_EXT
			 CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL2_TMR3_S_EXT, 0);
			 #endif
			 #ifdef TMR3_CLOCK_SOURCE_HIRC
			 CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL2_TMR3_S_HIRC, 0);
			 #endif				
	  #endif
		
	  #ifdef MCU_INTERFACE_ADC
		   CLK_EnableModuleClock(ADC_MODULE);
			 #ifdef ADC_CLOCK_SOURCE_HXT
       CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADC_S_HXT, CLK_ADC_CLK_DIVIDER(ADC_CLOCK_DIVIDER));
			 #endif
			 #ifdef ADC_CLOCK_SOURCE_LXT
       CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADC_S_LXT, CLK_ADC_CLK_DIVIDER(ADC_CLOCK_DIVIDER));
			 #endif
			 #ifdef ADC_CLOCK_SOURCE_PLL
       CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADC_S_PLL, CLK_ADC_CLK_DIVIDER(ADC_CLOCK_DIVIDER));
			 #endif
			 #ifdef ADC_CLOCK_SOURCE_HIRC
       CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADC_S_HIRC,CLK_ADC_CLK_DIVIDER(ADC_CLOCK_DIVIDER));
			 #endif	
	  #endif
		
	  #ifdef MCU_INTERFACE_DAC
		   CLK_EnableModuleClock(DAC_MODULE);
	  #endif		

	  #ifdef MCU_INTERFACE_I2C0
    CLK_EnableModuleClock(I2C0_MODULE);		
	  CLK_SetModuleClock(I2C0_MODULE, 0, 0);
	  #endif
	
	  #ifdef MCU_INTERFACE_I2C1
    CLK_EnableModuleClock(I2C1_MODULE);		
	  CLK_SetModuleClock(I2C1_MODULE, 0, 0);
	  #endif
 
	  #ifdef MCU_INTERFACE_PWM0
	    #ifdef PWM0_CH01_CLOCK_SOURCE_HXT
			  CLK_SetModuleClock(PWM0_CH01_MODULE, CLK_CLKSEL1_PWM0_CH01_S_HXT, 0);
				CLK_EnableModuleClock(PWM0_CH01_MODULE);
			#endif
			#ifdef PWM0_CH01_CLOCK_SOURCE_LXT
			  CLK_SetModuleClock(PWM0_CH01_MODULE, CLK_CLKSEL1_PWM0_CH01_S_LXT, 0);
				CLK_EnableModuleClock(PWM0_CH01_MODULE);
			#endif
			#ifdef PWM0_CH01_CLOCK_SOURCE_HCLK
			  CLK_SetModuleClock(PWM0_CH01_MODULE, CLK_CLKSEL1_PWM0_CH01_S_HCLK, 0);
				CLK_EnableModuleClock(PWM0_CH01_MODULE);
			#endif
			#ifdef PWM0_CH01_CLOCK_SOURCE_HIRC
			  CLK_SetModuleClock(PWM0_CH01_MODULE, CLK_CLKSEL1_PWM0_CH01_S_HIRC, 0);
				CLK_EnableModuleClock(PWM0_CH01_MODULE);
			#endif
			
	    #ifdef PWM0_CH23_CLOCK_SOURCE_HXT
			  CLK_SetModuleClock(PWM0_CH23_MODULE, CLK_CLKSEL1_PWM0_CH23_S_HXT, 0);
				CLK_EnableModuleClock(PWM0_CH23_MODULE);
			#endif
			#ifdef PWM0_CH23_CLOCK_SOURCE_LXT
			  CLK_SetModuleClock(PWM0_CH23_MODULE, CLK_CLKSEL1_PWM0_CH23_S_LXT, 0);
				CLK_EnableModuleClock(PWM0_CH23_MODULE);
			#endif
			#ifdef PWM0_CH23_CLOCK_SOURCE_HCLK
			  CLK_SetModuleClock(PWM0_CH23_MODULE, CLK_CLKSEL1_PWM0_CH23_S_HCLK, 0);
				CLK_EnableModuleClock(PWM0_CH23_MODULE);
			#endif
			#ifdef PWM0_CH23_CLOCK_SOURCE_HIRC
			  CLK_SetModuleClock(PWM0_CH23_MODULE, CLK_CLKSEL1_PWM0_CH23_S_HIRC, 0);
				CLK_EnableModuleClock(PWM0_CH23_MODULE);
			#endif
    #endif			

	  #ifdef MCU_INTERFACE_PWM1
	    #ifdef PWM1_CH01_CLOCK_SOURCE_HXT
			  CLK_SetModuleClock(PWM1_CH01_MODULE, CLK_CLKSEL1_PWM1_CH01_S_HXT, 0);
				CLK_EnableModuleClock(PWM1_CH01_MODULE);
			#endif
			#ifdef PWM1_CH01_CLOCK_SOURCE_LXT
			  CLK_SetModuleClock(PWM1_CH01_MODULE, CLK_CLKSEL1_PWM1_CH01_S_LXT, 0);
				CLK_EnableModuleClock(PWM1_CH01_MODULE);
			#endif
			#ifdef PWM1_CH01_CLOCK_SOURCE_HCLK
			  CLK_SetModuleClock(PWM1_CH01_MODULE, CLK_CLKSEL1_PWM1_CH01_S_HCLK, 0);
				CLK_EnableModuleClock(PWM1_CH01_MODULE);
			#endif
			#ifdef PWM1_CH01_CLOCK_SOURCE_HIRC
			  CLK_SetModuleClock(PWM1_CH01_MODULE, CLK_CLKSEL1_PWM1_CH01_S_HIRC, 0);
				CLK_EnableModuleClock(PWM1_CH01_MODULE);
			#endif
			
	    #ifdef PWM1_CH23_CLOCK_SOURCE_HXT
			  CLK_SetModuleClock(PWM1_CH23_MODULE, CLK_CLKSEL1_PWM1_CH23_S_HXT, 0);
				CLK_EnableModuleClock(PWM1_CH23_MODULE);
			#endif
			#ifdef PWM1_CH23_CLOCK_SOURCE_LXT
			  CLK_SetModuleClock(PWM1_CH23_MODULE, CLK_CLKSEL1_PWM1_CH23_S_LXT, 0);
				CLK_EnableModuleClock(PWM1_CH23_MODULE);
			#endif
			#ifdef PWM1_CH23_CLOCK_SOURCE_HCLK
			  CLK_SetModuleClock(PWM1_CH23_MODULE, CLK_CLKSEL1_PWM1_CH23_S_HCLK, 0);
				CLK_EnableModuleClock(PWM1_CH23_MODULE);
			#endif
			#ifdef PWM1_CH23_CLOCK_SOURCE_HIRC
			  CLK_SetModuleClock(PWM1_CH23_MODULE, CLK_CLKSEL1_PWM1_CH23_S_HIRC, 0);
				CLK_EnableModuleClock(PWM1_CH23_MODULE);
			#endif
    #endif
		
		#ifdef MCU_INTERFACE_UART0
		  CLK_EnableModuleClock(UART0_MODULE);
		  #ifdef UART_CLOCK_SOURCE_HXT
		  CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_UART_CLK_DIVIDER(UART_CLOCK_DIVIDER));
			#endif
		  #ifdef UART_CLOCK_SOURCE_LXT
		  CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_LXT, CLK_UART_CLK_DIVIDER(UART_CLOCK_DIVIDER));
			#endif			
			#ifdef UART_CLOCK_SOURCE_PLL
		  CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_PLL, CLK_UART_CLK_DIVIDER(UART_CLOCK_DIVIDER));
			#endif
		  #ifdef UART_CLOCK_SOURCE_HIRC
		  CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_HIRC, CLK_UART_CLK_DIVIDER(UART_CLOCK_DIVIDER));
			#endif			
		#endif

		#ifdef MCU_INTERFACE_UART1
		  CLK_EnableModuleClock(UART1_MODULE);
		  #ifdef UART_CLOCK_SOURCE_HXT
		  CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_UART_CLK_DIVIDER(UART_CLOCK_DIVIDER));
			#endif
		  #ifdef UART_CLOCK_SOURCE_LXT
		  CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART_S_LXT, CLK_UART_CLK_DIVIDER(UART_CLOCK_DIVIDER));
			#endif			
			#ifdef UART_CLOCK_SOURCE_PLL
		  CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART_S_PLL, CLK_UART_CLK_DIVIDER(UART_CLOCK_DIVIDER));
			#endif
		  #ifdef UART_CLOCK_SOURCE_HIRC
		  CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART_S_HIRC, CLK_UART_CLK_DIVIDER(UART_CLOCK_DIVIDER));
			#endif			
		#endif

    #ifdef MCU_INTERFACE_SPI0
      CLK_EnableModuleClock(SPI0_MODULE);			
			#ifdef SPI0_CLOCK_SOURCE_PLL
      CLK_SetModuleClock(SPI0_MODULE, CLK_CLKSEL2_SPI0_S_PLL, 0);
			#endif
			#ifdef SPI0_CLOCK_SOURCE_HCLK
      CLK_SetModuleClock(SPI0_MODULE, CLK_CLKSEL2_SPI0_S_HCLK, 0);			
			#endif			
		#endif 

    #ifdef MCU_INTERFACE_SPI1
      CLK_EnableModuleClock(SPI1_MODULE);
			#ifdef SPI1_CLOCK_SOURCE_PLL
      CLK_SetModuleClock(SPI1_MODULE, CLK_CLKSEL2_SPI1_S_PLL, 0);
			#endif
			#ifdef SPI1_CLOCK_SOURCE_HCLK
      CLK_SetModuleClock(SPI1_MODULE, CLK_CLKSEL2_SPI1_S_HCLK, 0);
			#endif			
		#endif 

    #ifdef MCU_INTERFACE_SPI2
      CLK_EnableModuleClock(SPI2_MODULE);
			#ifdef SPI2_CLOCK_SOURCE_PLL
      CLK_SetModuleClock(SPI2_MODULE, CLK_CLKSEL2_SPI2_S_PLL, 0);
			#endif
			#ifdef SPI2_CLOCK_SOURCE_HCLK
      CLK_SetModuleClock(SPI2_MODULE, CLK_CLKSEL2_SPI2_S_HCLK, 0);
			#endif			
		#endif 
		
    #ifdef MCU_INTERFACE_SC0
		   CLK_EnableModuleClock(SC0_MODULE);
			 #ifdef SC0_CLOCK_SOURCE_HXT
       CLK_SetModuleClock(SC0_MODULE, CLK_CLKSEL2_SC_S_HXT, CLK_SC0_CLK_DIVIDER(SC0_CLOCK_DIVIDER));
			 #endif
			 #ifdef SC0_CLOCK_SOURCE_PLL
       CLK_SetModuleClock(SC0_MODULE, CLK_CLKSEL2_SC_S_PLL, CLK_SC0_CLK_DIVIDER(SC0_CLOCK_DIVIDER));
			 #endif
			 #ifdef SC0_CLOCK_SOURCE_HIRC
       CLK_SetModuleClock(SC0_MODULE, CLK_CLKSEL2_SC_S_HIRC,CLK_SC0_CLK_DIVIDER(SC0_CLOCK_DIVIDER));
			 #endif			 
		#endif 
		
    #ifdef MCU_INTERFACE_SC1
		   CLK_EnableModuleClock(SC1_MODULE);
			 #ifdef SC1_CLOCK_SOURCE_HXT
       CLK_SetModuleClock(SC1_MODULE, CLK_CLKSEL2_SC_S_HXT, CLK_SC1_CLK_DIVIDER(SC1_CLOCK_DIVIDER));
			 #endif
			 #ifdef SC1_CLOCK_SOURCE_PLL
       CLK_SetModuleClock(SC1_MODULE, CLK_CLKSEL2_SC_S_PLL, CLK_SC1_CLK_DIVIDER(SC1_CLOCK_DIVIDER));
			 #endif
			 #ifdef SC1_CLOCK_SOURCE_HIRC
       CLK_SetModuleClock(SC1_MODULE, CLK_CLKSEL2_SC_S_HIRC,CLK_SC1_CLK_DIVIDER(SC1_CLOCK_DIVIDER));
			 #endif			 
		#endif

		#ifdef MCU_INTERFACE_LCD
		   CLK_EnableModuleClock(LCD_MODULE);
		   CLK_SetModuleClock(SC1_MODULE, CLK_CLKSEL1_LCD_S_LXT, 0);
    #endif
		
    // Init I/O Multi-function 
		
    // Set PA multi-function pins for ADC
	  #ifdef PIN_ADC_0
    SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA0_MFP_Msk) | SYS_PA_L_MFP_PA0_MFP_ADC_CH0;
		GPIO_DISABLE_DIGITAL_PATH(PA, BIT0);
	  #endif
	  #ifdef PIN_ADC_1
    SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA1_MFP_Msk) | SYS_PA_L_MFP_PA1_MFP_ADC_CH1;		
		GPIO_DISABLE_DIGITAL_PATH(PA, BIT1);		
	  #endif
	  #ifdef PIN_ADC_2
    SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA2_MFP_Msk) | SYS_PA_L_MFP_PA2_MFP_ADC_CH2;	
		GPIO_DISABLE_DIGITAL_PATH(PA, BIT2);		
	  #endif
	  #ifdef PIN_ADC_3
    SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA3_MFP_Msk) | SYS_PA_L_MFP_PA3_MFP_ADC_CH3;
		GPIO_DISABLE_DIGITAL_PATH(PA, BIT3);		
	  #endif
	  #ifdef PIN_ADC_4
    SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA4_MFP_Msk) | SYS_PA_L_MFP_PA4_MFP_ADC_CH4;
		GPIO_DISABLE_DIGITAL_PATH(PA, BIT4);		
	  #endif
		#ifdef PIN_ADC_5
    SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA5_MFP_Msk) | SYS_PA_L_MFP_PA5_MFP_ADC_CH5;	
		GPIO_DISABLE_DIGITAL_PATH(PA, BIT5);		
	  #endif
		#ifdef PIN_ADC_6
    SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA6_MFP_Msk) | SYS_PA_L_MFP_PA6_MFP_ADC_CH6;
		GPIO_DISABLE_DIGITAL_PATH(PA, BIT6);		
	  #endif
		#ifdef PIN_ADC_7
    SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA7_MFP_Msk) | SYS_PA_L_MFP_PA7_MFP_ADC_CH7;
		GPIO_DISABLE_DIGITAL_PATH(PA, BIT7);		
	  #endif
		#ifdef PIN_ADC_8
    SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD0_MFP_Msk) | SYS_PD_L_MFP_PD0_MFP_ADC_CH8;
		GPIO_DISABLE_DIGITAL_PATH(PD, BIT0);		
	  #endif		
		#ifdef PIN_ADC_9
    SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD1_MFP_Msk) | SYS_PD_L_MFP_PD1_MFP_ADC_CH9;
		GPIO_DISABLE_DIGITAL_PATH(PD, BIT1);		
	  #endif
		#ifdef PIN_ADC_10
    SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD2_MFP_Msk) | SYS_PD_L_MFP_PD2_MFP_ADC_CH10;
		GPIO_DISABLE_DIGITAL_PATH(PD, BIT2);		
	  #endif
		#ifdef PIN_ADC_11
    SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD3_MFP_Msk) | SYS_PD_L_MFP_PD3_MFP_ADC_CH11;
		GPIO_DISABLE_DIGITAL_PATH(PD, BIT3);		
	  #endif

		#ifdef PIN_DAC_0
    SYS->PC_L_MFP = (SYS->PC_L_MFP & ~SYS_PC_L_MFP_PC6_MFP_Msk) | SYS_PC_L_MFP_PC6_MFP_DAC_CH0;
		GPIO_DISABLE_DIGITAL_PATH(PC, BIT6);		
	  #endif
		#ifdef PIN_DAC_1
    SYS->PC_L_MFP = (SYS->PC_L_MFP & ~SYS_PC_L_MFP_PC7_MFP_Msk) | SYS_PC_L_MFP_PC7_MFP_DAC_CH1;
		GPIO_DISABLE_DIGITAL_PATH(PC, BIT7);		
	  #endif

    #ifdef MCU_INTERFACE_INT0_PB14
    SYS->PB_H_MFP = (SYS->PB_H_MFP & ~SYS_PB_H_MFP_PB14_MFP_Msk) | SYS_PB_H_MFP_PB14_MFP_EINT0;
		#endif
    #ifdef MCU_INTERFACE_INT0_PB9
    SYS->PB_H_MFP = (SYS->PB_H_MFP & ~SYS_PB_H_MFP_PB9_MFP_Msk) | SYS_PB_H_MFP_PB9_MFP_EINT0;
		#endif
    #ifdef MCU_INTERFACE_INT0_PC12
    SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC12_MFP_Msk) | SYS_PC_H_MFP_PC12_MFP_EINT0;
		#endif
    #ifdef MCU_INTERFACE_INT0_PF0
    SYS->PF_L_MFP = (SYS->PF_L_MFP & ~SYS_PF_L_MFP_PF0_MFP_Msk) | SYS_PF_L_MFP_PF0_MFP_EINT0;
		#endif
    #ifdef MCU_INTERFACE_INT0_PB8
    SYS->PB_H_MFP = (SYS->PB_H_MFP & ~SYS_PB_H_MFP_PB8_MFP_Msk) | SYS_PB_H_MFP_PB8_MFP_EINT0;
		#endif		
		
    #ifdef MCU_INTERFACE_INT1_PC13
    SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC13_MFP_Msk) | SYS_PC_H_MFP_PC13_MFP_EINT1;
		#endif
    #ifdef MCU_INTERFACE_INT1_PF1
    SYS->PF_L_MFP = (SYS->PF_L_MFP & ~SYS_PF_L_MFP_PF1_MFP_Msk) | SYS_PF_L_MFP_PF1_MFP_EINT1;
		#endif
    #ifdef MCU_INTERFACE_INT1_PB15
    SYS->PB_H_MFP = (SYS->PB_H_MFP & ~SYS_PB_H_MFP_PB15_MFP_Msk) | SYS_PB_H_MFP_PB15_MFP_EINT1;
		#endif
		
    #ifdef MCU_INTERFACE_I2C0
     #ifdef PIN_I2C0_SCL_PA9
		 SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA9_MFP_Msk) | SYS_PA_H_MFP_PA9_MFP_I2C0_SCL;
		 #endif
		 #ifdef PIN_I2C0_SDA_PA8
		 SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA8_MFP_Msk) | SYS_PA_H_MFP_PA8_MFP_I2C0_SDA;
		 #endif
     #ifdef PIN_I2C0_SCL_PC13
		 SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC13_MFP_Msk) | SYS_PC_H_MFP_PC13_MFP_I2C0_SCL;
		 #endif
		 #ifdef PIN_I2C0_SDA_PC12
		 SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC12_MFP_Msk) | SYS_PC_H_MFP_PC12_MFP_I2C0_SDA;
		 #endif
		 #ifdef PIN_I2C0_SCL_PA13
		 SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA13_MFP_Msk) | SYS_PA_H_MFP_PA13_MFP_I2C0_SCL;
		 #endif
		 #ifdef PIN_I2C0_SDA_PA12
		 SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA12_MFP_Msk) | SYS_PA_H_MFP_PA12_MFP_I2C0_SDA;
		 #endif	
		 #ifdef PIN_I2C0_SCL_PA5
		 SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA5_MFP_Msk) | SYS_PA_L_MFP_PA5_MFP_I2C0_SCL;
		 #endif
		 #ifdef PIN_I2C0_SDA_PA4
		 SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA4_MFP_Msk) | SYS_PA_L_MFP_PA4_MFP_I2C0_SDA;
		 #endif
		 #ifdef PIN_I2C0_SCL_PF5
		 SYS->PF_L_MFP = (SYS->PF_L_MFP & ~SYS_PF_L_MFP_PF5_MFP_Msk) | SYS_PF_L_MFP_PF5_MFP_I2C0_SCL;
		 #endif
		 #ifdef PIN_I2C0_SDA_PF4
		 SYS->PF_L_MFP = (SYS->PF_L_MFP & ~SYS_PF_L_MFP_PF4_MFP_Msk) | SYS_PF_L_MFP_PF4_MFP_I2C0_SDA;
		 #endif			 
		#endif
		
		#ifdef MCU_INTERFACE_I2C1
	   #ifdef PIN_I2C1_SCL_PA11
		 SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA11_MFP_Msk) | SYS_PA_H_MFP_PA11_MFP_I2C1_SCL;
		 #endif
		 #ifdef PIN_I2C1_SDA_PA10
		 SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA10_MFP_Msk) | SYS_PA_H_MFP_PA10_MFP_I2C1_SDA;
		 #endif
	   #ifdef PIN_I2C1_SCL_PC9
		 SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC9_MFP_Msk) | SYS_PC_H_MFP_PC9_MFP_I2C1_SCL;
		 #endif
		 #ifdef PIN_I2C1_SDA_PC8
		 SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC8_MFP_Msk) | SYS_PC_H_MFP_PC8_MFP_I2C1_SDA;
		 #endif	 
		#endif
		
		#ifdef MCU_INTERFACE_PWM0
		 #ifdef PIN_PWM0_CH0_PA12
     SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA12_MFP_Msk) | SYS_PA_H_MFP_PA12_MFP_PWM0_CH0;
		 #endif
		 #ifdef PIN_PWM0_CH1_PA13
     SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA13_MFP_Msk) | SYS_PA_H_MFP_PA13_MFP_PWM0_CH1;
		 #endif
		 #ifdef PIN_PWM0_CH2_PA14
     SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA14_MFP_Msk) | SYS_PA_H_MFP_PA14_MFP_PWM0_CH2;
		 #endif
		 #ifdef PIN_PWM0_CH3_PA15
     SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA15_MFP_Msk) | SYS_PA_H_MFP_PA15_MFP_PWM0_CH3;
		 #endif	
		 #ifdef PIN_PWM0_CH0_PC6
     SYS->PC_L_MFP = (SYS->PC_L_MFP & ~SYS_PC_L_MFP_PC6_MFP_Msk) | SYS_PC_L_MFP_PC6_MFP_PWM0_CH0;
		 #endif
		 #ifdef PIN_PWM0_CH1_PC7
     SYS->PC_L_MFP = (SYS->PC_L_MFP & ~SYS_PC_L_MFP_PC7_MFP_Msk) | SYS_PC_L_MFP_PC7_MFP_PWM0_CH1;
		 #endif
		 #ifdef PIN_PWM0_CH2_PA7
     SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA7_MFP_Msk) | SYS_PA_L_MFP_PA7_MFP_PWM0_CH2;
		 #endif
		 #ifdef PIN_PWM0_CH3_PA6
     SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA6_MFP_Msk)  | SYS_PA_L_MFP_PA6_MFP_PWM0_CH3;
		 #endif	
		#endif

		#ifdef MCU_INTERFACE_PWM1
		 #ifdef PIN_PWM1_CH0_PC12
     SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC12_MFP_Msk) | SYS_PC_H_MFP_PC12_MFP_PWM1_CH0;
		 #endif
		 #ifdef PIN_PWM1_CH1_PC13
     SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC13_MFP_Msk) | SYS_PC_H_MFP_PC13_MFP_PWM1_CH1;
		 #endif
		 #ifdef PIN_PWM1_CH2_PE0
     SYS->PE_L_MFP = (SYS->PE_L_MFP & ~SYS_PE_L_MFP_PE0_MFP_Msk) | SYS_PE_L_MFP_PE0_MFP_PWM1_CH2;
		 #endif
		 #ifdef PIN_PWM1_CH3_PE1
     SYS->PE_L_MFP = (SYS->PE_L_MFP & ~SYS_PE_L_MFP_PE1_MFP_Msk) | SYS_PE_L_MFP_PE1_MFP_PWM1_CH3;
		 #endif	
		 #ifdef PIN_PWM1_CH0_PB11
     SYS->PB_H_MFP = (SYS->PB_H_MFP & ~SYS_PB_H_MFP_PB11_MFP_Msk) | SYS_PB_H_MFP_PB11_MFP_PWM1_CH0;
		 #endif
		 #ifdef PIN_PWM1_CH1_PE5
     SYS->PE_L_MFP = (SYS->PE_L_MFP & ~SYS_PE_L_MFP_PE5_MFP_Msk) | SYS_PE_L_MFP_PE5_MFP_PWM1_CH1;
		 #endif
		 #ifdef PIN_PWM1_CH2_PC15
     SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC15_MFP_Msk) | SYS_PC_H_MFP_PC15_MFP_PWM1_CH2;
		 #endif
		 #ifdef PIN_PWM1_CH3_PC14
     SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC14_MFP_Msk)  | SYS_PC_H_MFP_PC14_MFP_PWM1_CH3;
		 #endif	
		#endif
		
		#ifdef MCU_INTERFACE_UART0
		 #ifdef PIN_UART0_RX_PB0
		 SYS->PB_L_MFP = (SYS->PB_L_MFP & ~SYS_PB_L_MFP_PB0_MFP_Msk)  | SYS_PB_L_MFP_PB0_MFP_UART0_RX;
		 #endif
		 #ifdef PIN_UART0_TX_PB1
		 SYS->PB_L_MFP = (SYS->PB_L_MFP & ~SYS_PB_L_MFP_PB1_MFP_Msk)  | SYS_PB_L_MFP_PB1_MFP_UART0_TX;
		 #endif		
		 #ifdef PIN_UART0_RX_PB2
		 SYS->PB_L_MFP = (SYS->PB_L_MFP & ~SYS_PB_L_MFP_PB2_MFP_Msk)  | SYS_PB_L_MFP_PB2_MFP_UART0_RTS;
		 #endif
		 #ifdef PIN_UART0_TX_PB3
		 SYS->PB_L_MFP = (SYS->PB_L_MFP & ~SYS_PB_L_MFP_PB3_MFP_Msk)  | SYS_PB_L_MFP_PB3_MFP_UART0_CTS;
		 #endif
		 #ifdef PIN_UART0_RX_PA14
		 SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA14_MFP_Msk)  | SYS_PA_H_MFP_PA14_MFP_UART0_RX;
		 #endif
		 #ifdef PIN_UART0_TX_PA15
		 SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA15_MFP_Msk)  | SYS_PA_H_MFP_PA15_MFP_UART0_TX;
		 #endif				 
		#endif
		
		#ifdef MCU_INTERFACE_UART1
		 #ifdef PIN_UART1_RX_PB4
		 SYS->PB_L_MFP = (SYS->PB_L_MFP & ~SYS_PB_L_MFP_PB4_MFP_Msk)  | SYS_PB_L_MFP_PB4_MFP_UART1_RX;
		 #endif
		 #ifdef PIN_UART1_TX_PB5
		 SYS->PB_L_MFP = (SYS->PB_L_MFP & ~SYS_PB_L_MFP_PB5_MFP_Msk)  | SYS_PB_L_MFP_PB5_MFP_UART1_TX;
		 #endif		
		 #ifdef PIN_UART1_RX_PB6
		 SYS->PB_L_MFP = (SYS->PB_L_MFP & ~SYS_PB_L_MFP_PB6_MFP_Msk)  | SYS_PB_L_MFP_PB6_MFP_UART1_RTS;
		 #endif
		 #ifdef PIN_UART1_TX_PB7
		 SYS->PB_L_MFP = (SYS->PB_L_MFP & ~SYS_PB_L_MFP_PB7_MFP_Msk)  | SYS_PB_L_MFP_PB7_MFP_UART1_CTS;
		 #endif
		 #ifdef PIN_UART1_RX_PC10
		 SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC10_MFP_Msk)  | SYS_PC_H_MFP_PC10_MFP_UART1_RX;
		 #endif
		 #ifdef PIN_UART1_TX_PC11
		 SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC11_MFP_Msk)  | SYS_PC_H_MFP_PC11_MFP_UART1_TX;
		 #endif	
		 #ifdef PIN_UART1_RX_PA2
		 SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA2_MFP_Msk)  | SYS_PA_L_MFP_PA2_MFP_UART1_RX;
		 #endif
		 #ifdef PIN_UART1_TX_PA3
		 SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA3_MFP_Msk)  | SYS_PA_L_MFP_PA3_MFP_UART1_TX;
		 #endif	
		 #ifdef PIN_UART1_RX_PD0
		 SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD0_MFP_Msk)  | SYS_PD_L_MFP_PD0_MFP_UART1_RX;
		 #endif
		 #ifdef PIN_UART1_TX_PD1
		 SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD1_MFP_Msk)  | SYS_PD_L_MFP_PD1_MFP_UART1_TX;
		 #endif		
		 #ifdef PIN_UART1_RX_PD2
		 SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD2_MFP_Msk)  | SYS_PD_L_MFP_PD2_MFP_UART1_RTS;
		 #endif
		 #ifdef PIN_UART1_TX_PD3
		 SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD3_MFP_Msk)  | SYS_PD_L_MFP_PD3_MFP_UART1_CTS;
		 #endif		 
		#endif	

    #ifdef MCU_INTERFACE_TMR0
		 #ifdef PIN_TC0_PA12
 	   SYS->PA_H_MFP  = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA12_MFP_Msk) | SYS_PA_H_MFP_PA12_MFP_TMR0_CAP;
     #endif
		 #ifdef PIN_TC0_PC6
 	   SYS->PC_L_MFP  = (SYS->PC_L_MFP & ~SYS_PC_L_MFP_PC6_MFP_Msk) | SYS_PC_L_MFP_PC6_MFP_TMR0_CAP;
     #endif	 
		 #ifdef PIN_TC0_PC15
		 SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC15_MFP_Msk) | SYS_PC_H_MFP_PC15_MFP_TMR0_CAP;
		 #endif
		 #ifdef PIN_TM0_PB8
		 SYS->PB_H_MFP = (SYS->PB_H_MFP & ~SYS_PB_H_MFP_PB8_MFP_Msk) | SYS_PB_H_MFP_PB8_MFP_TMR0_EXT;
		 #endif		 
		#endif

    #ifdef MCU_INTERFACE_TMR1
		 #ifdef PIN_TC1_PA13
 	   SYS->PA_H_MFP  = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA13_MFP_Msk) | SYS_PA_H_MFP_PA13_MFP_TMR1_CAP;
     #endif
		 #ifdef PIN_TC1_PC7
 	   SYS->PC_L_MFP  = (SYS->PC_L_MFP & ~SYS_PC_L_MFP_PC7_MFP_Msk) | SYS_PC_L_MFP_PC7_MFP_TMR1_CAP;
     #endif	 
		 #ifdef PIN_TM1_PB9
		 SYS->PB_H_MFP = (SYS->PB_H_MFP & ~SYS_PB_H_MFP_PB9_MFP_Msk) | SYS_PB_H_MFP_PB9_MFP_TMR1_EXT;
		 #endif	 
		#endif

    #ifdef MCU_INTERFACE_TMR2
		 #ifdef PIN_TC2_PA14
 	   SYS->PA_H_MFP  = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA14_MFP_Msk) | SYS_PA_H_MFP_PA14_MFP_TMR2_CAP;
     #endif	 		 
		 #ifdef PIN_TM2_PB10
 	   SYS->PB_H_MFP  = (SYS->PB_H_MFP & ~SYS_PB_H_MFP_PB10_MFP_Msk) | SYS_PB_H_MFP_PB10_MFP_TMR2_EXT;
     #endif			 	 
		#endif

    #ifdef MCU_INTERFACE_TMR3
		 #ifdef PIN_TC3_PA6
 	   SYS->PA_L_MFP  = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA6_MFP_Msk) | SYS_PA_L_MFP_PA6_MFP_TMR3_CAP;
     #endif	 	
		 #ifdef PIN_TC3_PA15
		 SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA15_MFP_Msk) | SYS_PA_H_MFP_PA15_MFP_TMR3_CAP;
		 #endif		 			 
		 #ifdef PIN_TM3_PB11
		 SYS->PB_H_MFP = (SYS->PB_H_MFP & ~SYS_PB_H_MFP_PB11_MFP_Msk) | SYS_PB_H_MFP_PB11_MFP_TMR3_EXT;
		 #endif		 
		#endif

    #ifdef MCU_INTERFACE_SPI0
     #ifdef PIN_SPI0_SS0_PC0
		 SYS->PC_L_MFP = (SYS->PC_L_MFP & ~SYS_PC_L_MFP_PC0_MFP_Msk) | SYS_PC_L_MFP_PC0_MFP_SPI0_SS0;
		 #endif
		 #ifdef PIN_SPI0_SCLK_PC1
		 SYS->PC_L_MFP = (SYS->PC_L_MFP & ~SYS_PC_L_MFP_PC1_MFP_Msk) | SYS_PC_L_MFP_PC1_MFP_SPI0_SCLK;
		 #endif
		 #ifdef PIN_SPI0_MISO0_PC2
		 SYS->PC_L_MFP = (SYS->PC_L_MFP & ~SYS_PC_L_MFP_PC2_MFP_Msk) | SYS_PC_L_MFP_PC2_MFP_SPI0_MISO0;
		 #endif
		 #ifdef PIN_SPI0_MOSI0_PC3
		 SYS->PC_L_MFP = (SYS->PC_L_MFP & ~SYS_PC_L_MFP_PC3_MFP_Msk) | SYS_PC_L_MFP_PC3_MFP_SPI0_MOSI0;
		 #endif
		 #ifdef PIN_SPI0_MISO1_PC4
		 SYS->PC_L_MFP = (SYS->PC_L_MFP & ~SYS_PC_L_MFP_PC4_MFP_Msk) | SYS_PC_L_MFP_PC4_MFP_SPI0_MISO1;
		 #endif
		 #ifdef PIN_SPI0_MOSI1_PC5
		 SYS->PC_L_MFP = (SYS->PC_L_MFP & ~SYS_PC_L_MFP_PC5_MFP_Msk) | SYS_PC_L_MFP_PC5_MFP_SPI0_MOSI1;
		 #endif
		 #ifdef PIN_SPI0_SS1_PB10
		 SYS->PB_H_MFP = (SYS->PB_H_MFP & ~SYS_PB_H_MFP_PB10_MFP_Msk) | SYS_PB_H_MFP_PB10_MFP_SPI0_SS1;
		 #endif
     #ifdef PIN_SPI0_SS0_PE1
		 SYS->PE_L_MFP = (SYS->PE_L_MFP & ~SYS_PE_L_MFP_PE1_MFP_Msk) | SYS_PE_L_MFP_PE1_MFP_SPI0_SS0;
		 #endif
		 #ifdef PIN_SPI0_SCLK_PE2
		 SYS->PE_L_MFP = (SYS->PE_L_MFP & ~SYS_PE_L_MFP_PE2_MFP_Msk) | SYS_PE_L_MFP_PE2_MFP_SPI0_SCLK;
		 #endif
		 #ifdef PIN_SPI0_MISO0_PE3
		 SYS->PE_L_MFP = (SYS->PE_L_MFP & ~SYS_PE_L_MFP_PE3_MFP_Msk) | SYS_PE_L_MFP_PE3_MFP_SPI0_MISO0;
		 #endif
		 #ifdef PIN_SPI0_MOSI0_PE4
		 SYS->PE_L_MFP = (SYS->PE_L_MFP & ~SYS_PE_L_MFP_PE4_MFP_Msk) | SYS_PE_L_MFP_PE4_MFP_SPI0_MOSI0;
		 #endif
		 #ifdef PIN_SPI0_MISO0_PB11
		 SYS->PB_H_MFP = (SYS->PB_H_MFP & ~SYS_PB_H_MFP_PB11_MFP_Msk) | SYS_PB_H_MFP_PB11_MFP_SPI0_MISO0;
		 #endif
		 #ifdef PIN_SPI0_MOSI0_PB10
		 SYS->PB_H_MFP = (SYS->PB_H_MFP & ~SYS_PB_H_MFP_PB10_MFP_Msk) | SYS_PB_H_MFP_PB10_MFP_SPI0_MOSI0;
		 #endif
		#endif

    #ifdef MCU_INTERFACE_SPI1
      #ifdef PIN_SPI1_SS1_PB9
		  SYS->PB_H_MFP = (SYS->PB_H_MFP & ~SYS_PB_H_MFP_PB9_MFP_Msk) | SYS_PB_H_MFP_PB9_MFP_SPI1_SS1;
		  #endif
      #ifdef PIN_SPI1_SS0_PC8
		  SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC8_MFP_Msk) | SYS_PC_H_MFP_PC8_MFP_SPI1_SS0;
		  #endif
		  #ifdef PIN_SPI1_SCLK_PC9
		  SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC9_MFP_Msk) | SYS_PC_H_MFP_PC9_MFP_SPI1_SCLK;
		  #endif
		  #ifdef PIN_SPI1_MISO0_PC10
		  SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC10_MFP_Msk) | SYS_PC_H_MFP_PC10_MFP_SPI1_MISO0;
		  #endif
	    #ifdef PIN_SPI1_MOSI0_PC11
		  SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC11_MFP_Msk) | SYS_PC_H_MFP_PC11_MFP_SPI1_MOSI0;
		  #endif
		  #ifdef PIN_SPI1_MISO1_PC12
		  SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC12_MFP_Msk) | SYS_PC_H_MFP_PC12_MFP_SPI1_MISO1;
		  #endif			
		  #ifdef PIN_SPI1_MOSI1_PC13
		  SYS->PC_H_MFP = (SYS->PC_H_MFP & ~SYS_PC_H_MFP_PC13_MFP_Msk) | SYS_PC_H_MFP_PC13_MFP_SPI1_MOSI1;
			#endif
		#endif

    #ifdef MCU_INTERFACE_SPI2
      #ifdef PIN_SPI2_SS1_PB14
		  SYS->PB_H_MFP = (SYS->PB_H_MFP & ~SYS_PB_H_MFP_PB14_MFP_Msk) | SYS_PB_H_MFP_PB14_MFP_SPI2_SS1;
		  #endif
      #ifdef PIN_SPI2_SS0_PD0
		  SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD0_MFP_Msk) | SYS_PD_L_MFP_PD0_MFP_SPI2_SS0;
		  #endif
		  #ifdef PIN_SPI2_SCLK_PD1
		  SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD1_MFP_Msk) | SYS_PD_L_MFP_PD1_MFP_SPI2_SCLK;
		  #endif
		  #ifdef PIN_SPI2_MISO0_PD2
		  SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD2_MFP_Msk) | SYS_PD_L_MFP_PD2_MFP_SPI2_MISO0;
		  #endif
	    #ifdef PIN_SPI2_MOSI0_PD3
		  SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD3_MFP_Msk) | SYS_PD_L_MFP_PD3_MFP_SPI2_MOSI0;
		  #endif
		  #ifdef PIN_SPI2_MISO1_PD4
		  SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD4_MFP_Msk) | SYS_PD_L_MFP_PD4_MFP_SPI2_MISO1;
		  #endif			
		  #ifdef PIN_SPI2_MOSI1_PD5
		  SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD5_MFP_Msk) | SYS_PD_L_MFP_PD5_MFP_SPI2_MOSI1;
			#endif
      #ifdef PIN_SPI2_SS0_PA8
		  SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA8_MFP_Msk) | SYS_PA_H_MFP_PA8_MFP_SPI2_SS0;
		  #endif
		  #ifdef PIN_SPI2_SCLK_PA9
		  SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA9_MFP_Msk) | SYS_PA_H_MFP_PA9_MFP_SPI2_SCLK;
		  #endif
		  #ifdef PIN_SPI2_MISO0_PA10
		  SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA10_MFP_Msk) | SYS_PA_H_MFP_PA10_MFP_SPI2_MISO0;
		  #endif
	    #ifdef PIN_SPI2_MOSI0_PA11
		  SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA11_MFP_Msk) | SYS_PA_H_MFP_PA11_MFP_SPI2_MOSI0;
		  #endif
			#ifdef PIN_SPI2_SS0_PB4
		  SYS->PB_L_MFP = (SYS->PB_L_MFP & ~SYS_PB_L_MFP_PB4_MFP_Msk) | SYS_PB_L_MFP_PB4_MFP_SPI2_SS0;
		  #endif
		  #ifdef PIN_SPI2_SCLK_PB5
		  SYS->PB_L_MFP = (SYS->PB_L_MFP & ~SYS_PB_L_MFP_PB5_MFP_Msk) | SYS_PB_L_MFP_PB5_MFP_SPI2_SCLK;
		  #endif
		  #ifdef PIN_SPI2_MISO0_PB6
		  SYS->PB_L_MFP = (SYS->PB_L_MFP & ~SYS_PB_L_MFP_PB6_MFP_Msk) | SYS_PB_L_MFP_PB6_MFP_SPI2_MISO0;
		  #endif
	    #ifdef PIN_SPI2_MOSI0_PB7
		  SYS->PB_L_MFP = (SYS->PB_L_MFP & ~SYS_PB_L_MFP_PB7_MFP_Msk) | SYS_PB_L_MFP_PB7_MFP_SPI2_MOSI0;
		  #endif
		#endif
		
		#ifdef MCU_INTERFACE_SC0
		  #ifdef PIN_SC0_RST_PA11
			SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA11_MFP_Msk) | SYS_PA_H_MFP_PA11_MFP_SC0_RST;
			#endif
		  #ifdef PIN_SC0_PWR_PA10
			SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA10_MFP_Msk) | SYS_PA_H_MFP_PA10_MFP_SC0_PWR;
			#endif
			#ifdef PIN_SC0_DAT_PA9
			SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA9_MFP_Msk) | SYS_PA_H_MFP_PA9_MFP_SC0_DAT;
			#endif
			#ifdef PIN_SC0_CLK_PA8
			SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA8_MFP_Msk) | SYS_PA_H_MFP_PA8_MFP_SC0_CLK;
			#endif
			#ifdef PIN_SC0_CD_PB4
			SYS->PB_L_MFP = (SYS->PB_L_MFP & ~SYS_PB_L_MFP_PB4_MFP_Msk) | SYS_PB_L_MFP_PB4_MFP_SC0_CD;
			#endif
		  #ifdef PIN_SC0_RST_PB5
			SYS->PB_L_MFP = (SYS->PB_L_MFP & ~SYS_PB_L_MFP_PB5_MFP_Msk) | SYS_PB_L_MFP_PB5_MFP_SC0_RST;
			#endif
			#ifdef PIN_SC0_PWR_PA15
			SYS->PA_H_MFP = (SYS->PA_H_MFP & ~SYS_PA_H_MFP_PA15_MFP_Msk) | SYS_PA_H_MFP_PA15_MFP_SC0_PWR;
			#endif
    #endif			

		#ifdef MCU_INTERFACE_SC1
		  #ifdef PIN_SC1_RST_PC3
			SYS->PC_L_MFP = (SYS->PC_L_MFP & ~SYS_PC_L_MFP_PC3_MFP_Msk) | SYS_PC_L_MFP_PC3_MFP_SC1_RST;
			#endif
		  #ifdef PIN_SC1_PWR_PC2
			SYS->PC_L_MFP = (SYS->PC_L_MFP & ~SYS_PC_L_MFP_PC2_MFP_Msk) | SYS_PC_L_MFP_PC2_MFP_SC1_PWR;
			#endif
			#ifdef PIN_SC1_DAT_PC1
			SYS->PC_L_MFP = (SYS->PC_L_MFP & ~SYS_PC_L_MFP_PC1_MFP_Msk) | SYS_PC_L_MFP_PC1_MFP_SC1_DAT;
			#endif
			#ifdef PIN_SC1_CLK_PC0
			SYS->PC_L_MFP = (SYS->PC_L_MFP & ~SYS_PC_L_MFP_PC0_MFP_Msk) | SYS_PC_L_MFP_PC0_MFP_SC1_CLK;
			#endif
			#ifdef PIN_SC1_CD_PC6
			SYS->PC_L_MFP = (SYS->PC_L_MFP & ~SYS_PC_L_MFP_PC6_MFP_Msk) | SYS_PC_L_MFP_PC6_MFP_SC1_CD;
			#endif
		  #ifdef PIN_SC1_RST_PD3
			SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD3_MFP_Msk) | SYS_PD_L_MFP_PD3_MFP_SC1_RST;
			#endif
		  #ifdef PIN_SC1_PWR_PD2
			SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD2_MFP_Msk) | SYS_PD_L_MFP_PD2_MFP_SC1_PWR;
			#endif
			#ifdef PIN_SC1_DAT_PD1
			SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD1_MFP_Msk) | SYS_PD_L_MFP_PD1_MFP_SC1_DAT;
			#endif
			#ifdef PIN_SC1_CLK_PD0
			SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD0_MFP_Msk) | SYS_PD_L_MFP_PD0_MFP_SC1_CLK;
			#endif
			#ifdef PIN_SC1_CD_PD4
			SYS->PD_L_MFP = (SYS->PD_L_MFP & ~SYS_PD_L_MFP_PD4_MFP_Msk) | SYS_PD_L_MFP_PD4_MFP_SC1_CD;
			#endif	
			#ifdef PIN_SC1_CD_PB15
			SYS->PB_h_MFP = (SYS->PB_H_MFP & ~SYS_PB_H_MFP_PB15_MFP_Msk) | SYS_PB_H_MFP_PB15_MFP_SC1_CD;
			#endif	
    #endif 

		#ifdef MCU_INTERFACE_SC2
		  #ifdef PIN_SC2_RST_PA5
			SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA5_MFP_Msk) | SYS_PA_L_MFP_PA5_MFP_SC2_RST;
			#endif
		  #ifdef PIN_SC2_PWR_PA4
			SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA4_MFP_Msk) | SYS_PA_L_MFP_PA4_MFP_SC2_PWR;
			#endif
			#ifdef PIN_SC2_DAT_PA7
			SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA7_MFP_Msk) | SYS_PA_L_MFP_PA7_MFP_SC2_DAT;
			#endif
			#ifdef PIN_SC2_CLK_PA6
			SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA6_MFP_Msk) | SYS_PA_L_MFP_PA6_MFP_SC2_CLK;
			#endif
			#ifdef PIN_SC2_CD_PA0
			SYS->PA_L_MFP = (SYS->PA_L_MFP & ~SYS_PA_L_MFP_PA0_MFP_Msk) | SYS_PA_L_MFP_PA0_MFP_SC2_CD;
			#endif	
			#ifdef PIN_SC2_PWR_PB8
			SYS->PB_H_MFP = (SYS->PB_H_MFP & ~SYS_PB_H_MFP_PB8_MFP_Msk) | SYS_PB_H_MFP_PB8_MFP_SC2_PWR;
			#endif
    #endif
		
    SYS_LockReg();  // Lock protected registers
}
