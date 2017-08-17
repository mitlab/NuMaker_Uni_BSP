//
// I2C_LCD_pingpong : LCD draw a bar and ball to emulate pingpong
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
#include "Draw2D.h"

#define PIXEL_ON  1
#define PIXEL_OFF 0
#define X0 15       // Circle initial X 
#define Y0 10       // Circle initial Y
#define R_BAR_X 120 // Right-Bar X-position
#define L_BAR_X 0   // Left-Bar  X-position
	
int32_t main (void)
{
  int dirX, dirY;
  int movX, movY;
  uint16_t r;
  uint16_t x, y;
  uint16_t fgColor, bgColor;
	
  SYS_Init();
  I2C_Open(I2C0, I2C0_CLOCK_FREQUENCY);	//set I2C0 running at 400KHz
  init_LCD();
	clear_LCD();	
	
	x = X0;    // circle center x
	y = Y0;    // circle center y
	r = 5;     // circle radius
	movX = 3;  // x movement
	movY = 3;  // y movement
	dirX = 1;  // x direction
	dirY = 1;  // y direction
	
	bgColor = BG_COLOR;
	while(1) 
		{
		 fgColor = FG_COLOR;
	   draw_Circle(x, y, r, fgColor, bgColor); // draw a circle
		 draw_Line(L_BAR_X,y-7, L_BAR_X,y+7, fgColor, bgColor); // draw left  line			
		 draw_Line(R_BAR_X,y-7, R_BAR_X,y+7, fgColor, bgColor); // draw right line

	   CLK_SysTickDelay(10000); // adjustable delay for vision
			
     fgColor = BG_COLOR;
	   draw_Circle(x, y, r, fgColor, bgColor); // erase a circle
     draw_Line(L_BAR_X,y-7,L_BAR_X,y+7, fgColor, bgColor); // draw left  line				
     draw_Line(R_BAR_X,y-7,R_BAR_X,y+7, fgColor, bgColor); // draw right line
							 
		 // boundary check for changing direction
     if      ((x-r) < L_BAR_X)  dirX=1;  
	   else if ((x+r) > R_BAR_X)  dirX=-1;
	   else if ((y-r) < 0)        dirY=1;  
	   else if ((y+r) > LCD_Ymax) dirY=-1;
			
	   x = x + dirX * movX; // change x of circle center
     y = y + dirY * movY; // change y of circle center							
   }
}
