//
// SPI_RFID-RC522 : RFID Reader RC522 reading RFID Tag
//
// EVB : NuMaker Uni
// MCU : NANO100NE3BN
// SPI : RFID-RC522
//
// RC522 RFID Reader
// SDA (SS) : connected to PC0/SPI1_SS 
// SCK (SCK): connected to PC1/SPI1_CLK  
// MOSI     : connected to PC3/SPI1_MOSI 
// MISO     : connected to PC2/SPI1_MISO 
// IRQ      : no connection
// GND      : connected to Gnd
// RST      : connected to 3.3V
// VCC      : connected to 3.3V

#include <stdio.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "SPI_RC522.h"

unsigned char UID[4],Temp[4]                                       ;
unsigned char RF_Buffer[18]                                        ;
unsigned char Password_Buffer[6]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}   ; // Mifare One ????

char          MBRX[30]                                             ;
char          MBKeyTP[30]                                          ;
char          Event                                                ;
unsigned char DISP_MODE,i                                          ; // ????????
unsigned char des_on       = 0                                     ; // DES????

void Auto_Reader(void)
{
	char Text[16];
  while(1)
  {
    if(PcdRequest(0x52,Temp)==MI_OK)
    {
      if(Temp[0]==0x04&&Temp[1]==0x00)  
				printf("MFOne-S50    \n");
      else if(Temp[0]==0x02&&Temp[1]==0x00)
				printf("MFOne-S70    \n");
      else if(Temp[0]==0x44&&Temp[1]==0x00)
				printf("MF-UltraLight\n");
      else if(Temp[0]==0x08&&Temp[1]==0x00)
				printf("MF-Pro       \n");
      else if(Temp[0]==0x44&&Temp[1]==0x03)
				printf("MF Desire    \n");
      else
        printf("Unknown Card \n");
			
      if(PcdAnticoll(UID)==MI_OK)
      { 
        printf("UID :%x %x %x %x\n", UID[0],UID[1],UID[2],UID[3]);
        //while (!(IFG1 & UTXIFG0));
        //TXBUF0 = '\n';
      }
			//else 
			//  printf("UID :           \n");
    }
		//else 
		//	printf("No Card      \n");    
  } 
}

void Init_SPI()
{
	SPI_Open(RC522_SPI_PORT, SPI_MASTER, SPI_MODE_0, RC522_SPI_DATAWIDTH, RC522_SPI_SPEED);
	SPI_DisableAutoSS(RC522_SPI_PORT);
	SPI_SET_MSB_FIRST(RC522_SPI_PORT);
}

int main( void )
{
	SYS_Init();
	
	GPIO_SetMode(PC, BIT13, GPIO_MODE_OUTPUT);
  PC13=1;
	
	Init_SPI();  // initialize SPI0
	
	printf("SPI_RC522 RFID Reader\n");
	
  PcdReset();
  PcdAntennaOn();
	
  Auto_Reader();
}
