/*
  Blink
 Turns on an LED on for one second, then off for one second, repeatedly.
 
 This example code is in the public domain.
 */

#include <LiquidCrystal.h>
#include "gamelib.h"

//Pin assignments for SainSmart LCD Keypad Shield
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 

Game_Class Game ;


long randNumber;
long int tab_sequence_easy[10] ;
long int tab_sequence_middle[10] ;
int first_loop = 1 ;
int btn_lcd = A0 ;

int my_putc( char c, FILE *t) {
  Serial.write( c );
}


void show_difficulty() // Display a text to chosse the difficulty
{

  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Choose your");
  lcd.setCursor(2, 1);
  lcd.print("difficulty :");
  delay(2000);
  lcd.clear();

  lcd.setCursor(2, 0);
  lcd.print("1:Left");
  lcd.setCursor(10, 0);
  lcd.print("2:Up");
  lcd.setCursor(4, 1);
  lcd.print("3:Right");
  delay(1000) ;
}

// the setup routine runs once when you press reset:
void setup() {                
  Serial.begin(9600) ;


  pinMode(btn_lcd, INPUT) ;

  Serial.println("SETUP()") ;

  lcd.begin(16, 2); // 16 columns and 2 lines
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Welcome to the");
  lcd.setCursor(2, 1);
  lcd.print("Gael's Game");
  delay(2500);
  lcd.clear();

  fdevopen( &my_putc, 0);
  randomSeed(analogRead(0)); // generate a pseudo-random number on an unconnected pin 


}

// the loop routine runs over and over again forever:
void loop() {

  int i = 0 ;
  int j = 0 ;
  int val_btn = 0 ;
  int btn_led_convert = 0 ;
  int difficulty = 0 ;

  char level_msg[24] = "" ;

  Game.reset_leds() ;  

  /* Diplay text to choose difficulty */

  show_difficulty() ;
  printf(" Return Difficulty : [%d]\n",difficulty );

  while ( btn_led_convert != 1 & btn_led_convert != 2 &  btn_led_convert != 3 )
  { 
    val_btn = analogRead(btn_lcd) ;
    btn_led_convert = Game.btn_to_led(val_btn) ;
    delay(10) ;
  }
  lcd.clear() ;
  printf("btn clicked for level : [%d]\n", btn_led_convert);

  sprintf(level_msg, "level %d", btn_led_convert) ;

  lcd.setCursor(3, 0);
  lcd.print("You chose");
  lcd.setCursor(4, 1);
  lcd.print(level_msg);

  delay(2500) ;

  // Generate a sequence depending on the difficulty level
  int sequence[10 * btn_led_convert] ;
  Game.generate_sequence(btn_led_convert, sequence) ;

  for ( i = 0 ; i < btn_led_convert*10 ; i++ )
    {
      printf("sequence : [%d][%d]\n", i, sequence[i]) ;
      Game.switch_on_led( sequence[i]) ; //sequence[i] ) ;
    }


  delay(1000) ;
}






















