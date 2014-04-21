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

// Pin connected to the different leds
int led_A = 24; // Up
int led_B = 30; // Left
int led_C = 36; // Right
int led_D = 42; // Down
long randNumber;
long int tab_sequence_easy[10] ;
long int tab_sequence_middle[10] ;
int first_loop = 1 ;
int btn_lcd = A0 ;

int my_putc( char c, FILE *t) {
  Serial.write( c );
}

void reset_leds() // Switch off all the leds
{
  digitalWrite(led_A, LOW);
  digitalWrite(led_B, LOW);  
  digitalWrite(led_C, LOW);
  digitalWrite(led_D, LOW);
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

void generate_sequence( long int tab_sequence[10] )
{
  int i = 0 ;

  for (i=0; i < 10 ; i++ )
    tab_sequence[i] = random(1, 5) ;

}

void reset_sequence( long int tab_sequence[10] )
{
  int i = 0 ;

  for (i=0; i < 10 ; i++ )
    tab_sequence[i] = 0 ;

}



// the setup routine runs once when you press reset:
void setup() {                
  Serial.begin(9600) ;
  // initialize the digital pin as an output.
  pinMode(led_A, OUTPUT);     
  pinMode(led_B, OUTPUT);     
  pinMode(led_C, OUTPUT);     
  pinMode(led_D, OUTPUT);

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

  reset_sequence( tab_sequence_easy ) ;
  generate_sequence( tab_sequence_easy ) ;

}

// the loop routine runs over and over again forever:
void loop() {

  int i = 0 ;
  int j = 0 ;
  int val_btn = 0 ;
  int btn_led_convert = 0 ;
  int difficulty = 0 ;

  char level_msg[24] = "" ;

  reset_leds() ;  

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

  /*

  // for (i=0; i <10; i++ )
  //   printf("tab_sequence_middle[%d] : %d\n", i, tab_sequence_middle[i]);
  // printf("\n") ;
  /*
  randNumber = random(1, 5);
   Serial.println(randNumber);
   
   
   if(randNumber == 1 )
   digitalWrite(led_A, HIGH); 
   else if (randNumber == 2 )
   digitalWrite(led_B, HIGH);
   else if (randNumber == 3 )
   digitalWrite(led_C, HIGH);
   else if (randNumber == 4 )
   digitalWrite(led_D, HIGH);
   else
   reset_leds() ;
   delay(500);
   */
  delay(1000) ;
}



















