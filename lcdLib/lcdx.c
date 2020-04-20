/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

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
  u_char j;
  u_char i;
  u_char k;
  clearScreen(COLOR_BLUE);

  // drawString5x7(20,20, "hello", COLOR_GREEN, COLOR_RED);

  //fillRectangle(30,30, 60, 60, COLOR_ORANGE);
  for(j=0; j < 15; j++){
    drawPixel(0,j,COLOR_BLACK);
    drawPixel(j,15,COLOR_BLACK);
    drawPixel(j,j,COLOR_BLACK);
  }
}
