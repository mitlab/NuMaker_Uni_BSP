//
// SPI_NRF24L01 : nRF24L01 Tranmitter & Receiver Testing
//
// EVB : NuMaker Uni
// MCU : NANO100NE3BN
// SPI : NRF24L01 (RF2.4G module)

// RF24L01 to J2 Connections 
// pin1 GND
// pin2 VCC : VCC3 (3.3V)
// pin3 CE  : PB3
// pin4 CS  : PC0/SPI0_SS0
// pin5 SCLK: PC1/SPI0_CLK
// pin6 MOSI: PC3/SPI0_MOSI0
// pin7 MISO: PC2/SPI0_MISO0
// pin8 IRQ : PB2

#include <stdio.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "NRF24L01.h"

#define TRANSMITTER

uint16_t TransferCount =0;

int main(void)
{
//	char Text[16] = "                ";
  char Data[NRF24L01_PAYLOAD] = "Hello";
	uint8_t Tx_address[5] = {0x34, 0x43, 0x10, 0x10, 0x01};
	uint8_t Rx_address[5] = {0x34, 0x43, 0x10, 0x10, 0x01};

	SYS_Init();	

	nRF_Init();
	nRF_config(NRF24L01_CHANNEL, NRF24L01_PAYLOAD); // channel #, payload
  nRF_setTADDR(Tx_address);
  nRF_setRADDR(Rx_address); 
	
	printf("SPI NRF24L01 ");
#ifdef TRANSMITTER
  printf("Transmitting...\n");		
#else
	printf("Receiving.......\n");	
#endif

	while(1)
	{		
#ifdef TRANSMITTER	
			printf("%s, ",Data);			
			nRF_send(Data);
			printf("%d\n",TransferCount);
			TransferCount++;
		  CLK_SysTickDelay(50000);
#else	
		  if (nRF_dataReady()) {
			nRF_getData(Data);					
			printf("%s, ",Data);	
			printf("%d\n",TransferCount);
			TransferCount++;
			}	
#endif	
	}
}
