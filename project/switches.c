#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "assemblyCode.h"
#include "toyShapes.h"

char play_both;
char play_red;
char play_green;

int state = 0;

static char switch_update_interrupt_sense(){
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void switch_init(){
  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  switch_interrupt_handler();
}


void switch_interrupt_handler(){
  play_both = 0;
  play_red = 0;
  play_green = 0;
  char p2val = switch_update_interrupt_sense();

  // If Statements to Cycle through states //
  // Uses jump table found in assemblyCode.s and lcd code found in toyShapes.c

  if(p2val & SW1 ? 0 : 1){ // If we press button one we will play the pokemon theme and lcd
    
    PokemonLCD();
    switch_state_call(1);
  }
  
  if(p2val & SW2 ? 0 : 1){ // Mario theme and Mario lcd

    MarioLCD();
    switch_state_call(2);
    play_both = 0;
    play_red = 1;
  }
  
  if(p2val & SW3 ? 0 : 1){ // Play tune and Display my name bouncing around the screen

    NameLCD();
    switch_state_call(3);
  }
  
  if(p2val & SW4 ? 0 : 1){ // display scres moving around screen lcd 
    
    SquaresLCD();
  }
}
