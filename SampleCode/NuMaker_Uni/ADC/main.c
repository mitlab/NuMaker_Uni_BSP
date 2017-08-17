//
// ADC : Analog-to-Digital Converter to read Sensor
//
// EVB : NuMaker Uni
// MCU : Nano100NE3BN
// ADC : ADC1 & ADC2

// JP6 connections
// pin1 ADC_MQ : PA2/ADC2
// pin2 ADC_DO : PA1/ADC1
#include <stdio.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"

void ADC_IRQHandler(void)
{
    uint8_t u8_Flag;
    uint16_t u16_ADC1value, u16_ADC2value;	

    // Get ADC conversion finish interrupt flag
    u8_Flag = ADC_GET_INT_FLAG(ADC, ADC_ADF_INT);

    if(u8_Flag & ADC_ADF_INT) {
        u16_ADC1value = ADC_GET_CONVERSION_DATA(ADC, 1);
        printf("ADC1=%d,",u16_ADC1value);
        u16_ADC2value = ADC_GET_CONVERSION_DATA(ADC, 2);			
        printf("ADC2=%d\n",u16_ADC2value);
    }
    ADC_CLR_INT_FLAG(ADC, u8_Flag);
}

void Init_ADC(void)
{
    ADC_Open(ADC, ADC_INPUT_MODE, ADC_OPERATION_MODE, ADC_CHANNEL_MASK );
    ADC_POWER_ON(ADC);
    ADC_EnableInt(ADC, ADC_ADF_INT);
    NVIC_EnableIRQ(ADC_IRQn);
    ADC_START_CONV(ADC);
}

int32_t main()
{	
    SYS_Init();
    Init_ADC();

    while(1) {
    }
}
