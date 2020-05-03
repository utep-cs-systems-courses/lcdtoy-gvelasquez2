#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;
  u_char r;
  u_char colLeft;
  u_char colRight;
  u_char c;
  clearScreen(COLOR_BLUE);
  drawTriangle(30);
}

void drawTriangle(u_char size){ // currently draws 4 triangles which for ma square with a diamond in center 
   u_char c,r,colLeft,colRight;
    for(r = 0; r <= size; r++){
      colLeft = size -r;
      colRight = size;
      for(c =colLeft; c<= colRight; c++){
	drawPixel(65+c,80+r,COLOR_GREEN);
	drawPixel(65-c,80+r,COLOR_BLACK);
	drawPixel(65+c,80-r,COLOR_RED);
	drawPixel(65-c,80-r,COLOR_WHITE);
      }
    }
  }
