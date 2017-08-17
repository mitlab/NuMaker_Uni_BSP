//
// I2C_LCD : display Text on LCD
//
// EVB : NuMaker Uni
// MCU : Nano100NE3BN
// LCD : I2C OLED 128x64

// JP2 connection
// PA9/I2C0-SCL to LCD's SCL
// PA8/I2C0-SDA to LCD's SDA

#include <stdio.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "I2C_SSD1306Z.h"

int32_t main()
{
    SYS_Init();
    I2C_Open(I2C0, I2C0_CLOCK_FREQUENCY);

    init_LCD();
    clear_LCD();
	
    print_Line(0, "NuMaker UNI     ");
    print_Line(1, "NANO100B  @42MHz");
    print_Line(2, "Low Power MCU   ");
    print_Line(3, "0.96 OLED 128x64");
    while(1);
}
