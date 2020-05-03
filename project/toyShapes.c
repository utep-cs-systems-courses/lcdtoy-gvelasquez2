#include "lcdutils.h"
#include "lcddraw.h"
#include "toyShapes.h"



// Draws a pokeball using rectangles and prints lyrics from the song on screen
void PokemonLCD(){
  lcd_init();
  clearScreen(COLOR_BLUE);
  drawString5x7(5,10,"Gotta Catch 'Em All!",COLOR_YELLOW,COLOR_BLUE);
  drawString5x7(40,20,"POKEMON!",COLOR_YELLOW,COLOR_BLUE);
  int x;
  int y;
  for(x = 25; x <= 105; x++){
    for(y = 40; y <= 80; y++){
      drawPixel(x,y,COLOR_RED);
      drawPixel(x,y+40,COLOR_WHITE);
      drawPixel((x/5)+50,(y/5)+68,COLOR_BLACK);
    }
  }
}

// Displays mario's catchphrase 
void MarioLCD(){
  lcd_init();
  clearScreen(COLOR_RED);
  drawString5x7(10,80,"It's a MARIO TIME",COLOR_BLACK,COLOR_RED);
}

// Displays my name "GIlbert" bouncing around screen"
void NameLCD(){
  lcd_init();
  clearScreen(COLOR_BLUE);
  int x;
  int y;
  int count;
  for(count = 0; count < 3; count++){
    __delay_cycles(4000000);
    drawString5x7(10,10,"GILBERT",COLOR_GREEN,COLOR_BLUE);
    __delay_cycles(4000000);
    clearScreen(COLOR_BLUE);
    __delay_cycles(4000000);
    drawString5x7(80,10,"GILBERT",COLOR_GREEN,COLOR_BLUE);
    __delay_cycles(4000000);
    clearScreen(COLOR_BLUE);
    __delay_cycles(4000000);
    drawString5x7(10,80,"GILBERT",COLOR_GREEN,COLOR_BLUE);
    __delay_cycles(4000000);
    clearScreen(COLOR_BLUE);
    __delay_cycles(4000000);
    drawString5x7(80,80,"GILBERT",COLOR_GREEN,COLOR_BLUE);
    __delay_cycles(4000000);
    clearScreen(COLOR_BLUE);
  }
  drawString5x7(40,60,"GILBERT",COLOR_RED,COLOR_BLUE);
}

// Draws four squares that move across the screen until interrupted 
void SquaresLCD(){
  lcd_init();
  clearScreen(COLOR_GREEN);
  int x = 0;
  int y = 0;
  while(1){
    fillRectangle(x,y,20,20,COLOR_BLUE);
    fillRectangle(x+10,y+30,20,20,COLOR_RED);
    fillRectangle(x+20,y+60,20,20,COLOR_YELLOW);
    fillRectangle(x+30,y+90,20,20,COLOR_VIOLET);
    x+=2;
    y+=2;
    if(x==100 || y == 100){
      x = 0;
      y= 0;
    }
    __delay_cycles(1000000);
    clearScreen(COLOR_GREEN);
  }
}
