#include <LiquidCrystal.h>
#include "Arduino.h"
#include "gamelib.h"

Game_Class::Game_Class()
{

}

int Game_Class::btn_to_led( int val_btn ) // Conversion from button pressed to LED (Obviously this is a virtual conversion)
{

  int btn_led_convert = -1 ; 
  int previous_btn = 0 ;

  if ( val_btn == 0 ) // LED C
  {
    printf("RIGHT button\n") ;
    btn_led_convert = 3 ;
  }
  else if ( val_btn > 130 && val_btn < 150 ) // LED B
  {
    printf("UP button\n") ;
    btn_led_convert = 2 ; 
  }
  else if ( val_btn > 310 && val_btn < 340 ) // LED D
  {
    printf("DOWN button\n") ;
    btn_led_convert = 4 ;
  }
  else if ( val_btn > 490 && val_btn < 510 ) // LED A
  {
    printf("LEFT button\n") ;
    btn_led_convert = 1 ;
  }
  else if ( val_btn > 730 && val_btn < 750 )
  {
    printf("SELECT button\n") ;
    btn_led_convert = 5 ;
  }
  else if ( val_btn > 1020 )
  {
    //   printf("NO button\n") ;
    btn_led_convert = 0 ;
  }

  previous_btn = btn_led_convert ;

  return btn_led_convert ; 
}

void Game_Class::generate_sequence(int difficulty, int* sequence)
{
  // Write a sequence and send it back
  
  
}

