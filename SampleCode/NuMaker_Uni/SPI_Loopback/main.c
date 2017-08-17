//
// SPI_Loopback: SPI MOSI to MISO loopback test
//
// EVB : NuMaker Uni
// MCU : NANO100NE3BN
// SPI : NRF24L01 (RF2.4G module)

// J2 Connections 
// pin1 GND
// pin2 VCC3 : Vcc 3.3V
// pin3 PB3  : SPI_CE
// pin4 PC0/SPI0_SS0  : SPI_CS
// pin5 PC1/SPI0_CLK  : SPI_SCLK
// pin6 PC3/SPI0_MOSI0: SPI_MOSI
// pin7 PC2/SPI0_MISO0: SPI_MISO
// pin8 PB2           : SPI_IRQ
// 
#include <stdio.h>
#include <string.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"

void SPI_Init(void)
{   // set SPI0, mode 0, 32bit, 20MHz, enable AutoSS (active-low)
    SPI_Open(SPI0, SPI_MASTER, SPI_MODE_0, 8, SPI0_CLOCK_FREQUENCY);
    SPI_EnableAutoSS(SPI0, SPI_SS0, SPI_SS0_ACTIVE_LOW);
}

int main(void)
{
    uint8_t i;
    uint32_t TestCount =0;
    char SrcData[16],DestData[16];

    SYS_Init();
    SPI_Init();

    printf("SPI0 Loopback Test\n");
	
    TestCount=0;
	
    while(1) {
      sprintf(SrcData,"TX = %6d   ", TestCount);
      printf("%s\n", SrcData);
			
      for (i=0; i<16; i++) {
	// TX
        SPI_WRITE_TX0(SPI0, SrcData[i]);
        SPI_TRIGGER(SPI0);
        while(SPI_IS_BUSY(SPI0));			
	// RX
	    DestData[i] = SPI_READ_RX0(SPI0);
      }
			DestData[0]='R';
      printf("%s\n", DestData);			
      TestCount++;		}
}
