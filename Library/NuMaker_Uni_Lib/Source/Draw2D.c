//
// Draw2D Graphics Driver
//
#include <stdio.h>
#include <string.h>
#include "Nano100Series.h"
#include "I2C_SSD1306Z.h"

// Bresenham Line Draw
void draw_Line(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t fgColor, uint16_t bgColor)
{
    int16_t dy = y2 - y1;
    int16_t dx = x2 - x1;
    int16_t stepx, stepy;

    if (dy < 0) { dy = -dy;  stepy = -1; } else { stepy = 1; }
    if (dx < 0) { dx = -dx;  stepx = -1; } else { stepx = 1; }
    dy <<= 1;        // dy is now 2*dy
    dx <<= 1;        // dx is now 2*dx

    draw_Pixel(x1,y1, fgColor, bgColor);
    if (dx > dy) 
    {
        int fraction = dy - (dx >> 1);  // same as 2*dy - dx
        while (x1 != x2) 
        {
           if (fraction >= 0) 
           {
               y1 += stepy;
               fraction -= dx;          // same as fraction -= 2*dx
           }
           x1 += stepx;
           fraction += dy;              // same as fraction -= 2*dy
           draw_Pixel(x1, y1, fgColor, bgColor);
        }
     } else {
        int fraction = dx - (dy >> 1);
        while (y1 != y2) {
           if (fraction >= 0) {
               x1 += stepx;
               fraction -= dy;
           }
           y1 += stepy;
           fraction += dx;
           draw_Pixel(x1, y1, fgColor, bgColor);
        }
     }
}

// Optimized Circle Draw
void draw_Circle(int16_t xc, int16_t yc, int16_t r, uint16_t fgColor, uint16_t bgColor)
{
    uint16_t x= r, y= 0;//local coords     
    int          cd2= 0;    //current distance squared - radius squared

    if (!r) return; 
    draw_Pixel(xc-r, yc, fgColor, bgColor);
    draw_Pixel(xc+r, yc, fgColor, bgColor);
    draw_Pixel(xc, yc-r, fgColor, bgColor);
    draw_Pixel(xc, yc+r, fgColor, bgColor);
 
    while (x > y)    //only formulate 1/8 of circle
    {
        cd2-= (--x) - (++y);
        if (cd2 < 0) cd2+=x++;

        draw_Pixel(xc-x, yc-y, fgColor, bgColor);//upper left left
        draw_Pixel(xc-y, yc-x, fgColor, bgColor);//upper upper left
        draw_Pixel(xc+y, yc-x, fgColor, bgColor);//upper upper right
        draw_Pixel(xc+x, yc-y, fgColor, bgColor);//upper right right
        draw_Pixel(xc-x, yc+y, fgColor, bgColor);//lower left left
        draw_Pixel(xc-y, yc+x, fgColor, bgColor);//lower lower left
        draw_Pixel(xc+y, yc+x, fgColor, bgColor);//lower lower right
        draw_Pixel(xc+x, yc+y, fgColor, bgColor);//lower right right
     } 
}

void draw_Rectangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t fgColor, uint16_t bgColor)
{
	int16_t x,y, tmp;
	if (x0>x1) { tmp = x1; x1 = x0; x0 = tmp; }
	if (y0>y1) { tmp = y1; y1 = y0; y0 = tmp; }
  for (x=x0; x<=x1; x++) draw_Pixel(x,y0,fgColor, bgColor);
	for (y=y0; y<=y1; y++) draw_Pixel(x0,y,fgColor, bgColor);
	for (x=x0; x<=x1; x++) draw_Pixel(x,y1,fgColor, bgColor);
 	for (y=y0; y<=y1; y++) draw_Pixel(x1,y,fgColor, bgColor);		
}

void fill_Rectangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t fgColor, uint16_t bgColor)
{
	int16_t x,y, tmp;
	if (x0>x1) { tmp = x1; x1 = x0; x0 = tmp; }
	if (y0>y1) { tmp = y1; y1 = y0; y0 = tmp; } 
    for (x=x0; x<=x1; x++) {
		for (y=y0; y<=y1; y++) 	{
			draw_Pixel(x,y, fgColor, bgColor);	
			}
		}
}

void draw_Triangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t fgColor, uint16_t bgColor)
{
	draw_Line(x0, y0, x1, y1, fgColor, bgColor);
	draw_Line(x1, y1, x2, y2, fgColor, bgColor);
	draw_Line(x0, y0, x2, y2, fgColor, bgColor);
}
