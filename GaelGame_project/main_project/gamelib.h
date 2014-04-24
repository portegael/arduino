#ifndef GAMELIB_h
#define GAMELIB_h

#include "Arduino.h"
#include <LiquidCrystal.h>

#define SAMPLE_WAIT -1
#define NO_KEY 0
#define UP_KEY 3
#define DOWN_KEY 4
#define LEFT_KEY 2
#define RIGHT_KEY 5
#define SELECT_KEY 1

class Game_Class
{
public:
  Game_Class() ;
  void reset_leds() ;
  int btn_to_led( int val_btn ) ; // Conversion from button pressed to LED (Obviously this is a virtual conversion)
  void generate_sequence(int difficulty, int* sequence) ;
  void switch_on_led( int led ) ;

private:

  // Pin connected to the different leds
  int led_A = 24; // Up
  int led_B = 30; // Left
  int led_C = 36; // Right
  int led_D = 42; // Down

};

#endif


