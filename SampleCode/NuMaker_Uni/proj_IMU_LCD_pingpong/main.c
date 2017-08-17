//
// proj_IMU_LCD_pingpong : project using IMU to move the bar and bounce the ball back
//
// EVB : NuMaker Uni
// MCU : Nano102ZC2AN
// IMU : MPU6500

// I2C1 to LCD
// PC10/I2C1-SCL to I2C-Slave SCL
// PC11/I2C1-SDA to I2C-Slave SDA

#include <stdio.h>
#include <math.h>
#include "Nano100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "I2C_SSD1306Z.h"
#include "Draw2D.h"
#include "MPU6500.h"
#define PI 3.1415926535

#define PIXEL_ON  1
#define PIXEL_OFF 0
#define X0 15       // Circle initial X 
#define Y0 10       // Circle initial Y
#define BAR_X 64    // Bar initial X
#define BAR_Y 63    // Bar initial Y
	
int32_t main (void)
{
	int16_t accX, accY, accZ;
  float theta;
	
	int dirX_BAR, movX_BAR;
	int dirX, dirY;
	int movX, movY;
	uint16_t r;
	uint16_t x, y;
	uint16_t BAR_x, BAR_y, BAR_l;	
	uint16_t fgColor, bgColor;
	
  SYS_Init();
  I2C_Open(I2C0, I2C0_CLOCK_FREQUENCY);	//set I2C0 running at 400KHz
  init_LCD();
	clear_LCD();	
  I2C_Open(I2C1, I2C1_CLOCK_FREQUENCY);	//set I2C1 running at 400KHz	
	Init_MPU6500();
	
	x = X0;    // circle center x
	y = Y0;    // circle center y
	r = 5;     // circle radius
	
	BAR_x = BAR_X;
	BAR_y = BAR_Y;
	BAR_l = 7;
	
	movX = 1;  // x movement
	movY = 1;  // y movement
	dirX = 1;  // x direction
	dirY = 1;  // y direction

	dirX_BAR =0;
	movX_BAR =3;
	
	bgColor = BG_COLOR;
	while(1) {
		 fgColor = FG_COLOR;
	   draw_Circle(x, y, r, fgColor, bgColor); // draw a circle
		 draw_Line(BAR_x-BAR_l,BAR_y, BAR_x+BAR_l,BAR_y, fgColor, bgColor); // draw a line 

	   CLK_SysTickDelay(1000); // adjustable delay for vision
			
     fgColor = BG_COLOR;
	   draw_Circle(x, y, r, fgColor, bgColor); // erase a circle
     draw_Line(BAR_x-BAR_l,BAR_y, BAR_x+BAR_l,BAR_y, fgColor, bgColor); // draw a line				

		 // read Accelerometer to calculate tilt angle
     accX = Read_MPU6500_AccX();
     accY = Read_MPU6500_AccY();
     accZ = Read_MPU6500_AccZ();
     theta = atan(accX / sqrt(pow(accY,2)+pow(accZ,2))) *180 /PI;
 	
		 if      (theta<-20) dirX_BAR= 1;
		 else if (theta> 20) dirX_BAR=-1;
		 else                dirX_BAR= 0;

		 // boundary check for changing direction
     if      ((x-r) <=0)        dirX=1;  
	   else if ((x+r) > LCD_Xmax) dirX=-1;
		 
		 if ((y-r) <=0)             dirY=1;
	   else if ((y+r) >= BAR_y)
			    if (((x+r) < BAR_x-BAR_l) || ((x-r) > BAR_x+BAR_l)) y=0;
		      else                  dirY=-1;
					
	   x = x + dirX * movX; // change x of circle center
     y = y + dirY * movY; // change y of circle center
		 
     BAR_x = BAR_x + dirX_BAR * movX_BAR;
     if ((BAR_x-BAR_l)<0       ) BAR_x=LCD_Xmax-BAR_l;
		 if ((BAR_x+BAR_l)>LCD_Xmax) BAR_x=BAR_l;
   }
}
