/*
  Blink
 Turns on an LED on for one second, then off for one second, repeatedly.
 
 This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led_A = 24;
int led_B = 30;
int led_C = 36;
int led_D = 42;
long randNumber;
long int tab_sequence_easy[10] ;
long int tab_sequence_middle[10] ;
int first_loop = 1 ;
int btn_lcd = A0 ;

int my_putc( char c, FILE *t) {
  Serial.write( c );
}

void reset_leds() {
  digitalWrite(led_A, LOW);
  digitalWrite(led_B, LOW);  
  digitalWrite(led_C, LOW);
  digitalWrite(led_D, LOW);
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

int btn_to_led( int val_btn ) // Conversion from button pressed to LED (Obviously this is a virtual conversion)
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

  fdevopen( &my_putc, 0);
  randomSeed(analogRead(0)); // generate a pseudo-random number on an unconnected team 

  reset_sequence( tab_sequence_easy ) ;
  generate_sequence( tab_sequence_easy ) ;

  //  reset_sequence( tab_sequence_middle ) ;
  //  generate_sequence( tab_sequence_middle ) ;


}

// the loop routine runs over and over again forever:
void loop() {
  int i = 0 ;
  int j = 0 ;
  int val_btn = 0 ;
  int btn_led_convert = 0 ;
  reset_leds() ;  

  val_btn = analogRead(btn_lcd) ;
  btn_led_convert = btn_to_led(val_btn) ;
  delay(150) ;
  // printf("val_btn : %d\n", val_btn) ;
  //  Serial.println(val_btn);

  /* for (i=0; i <10; i++ )
   {    
   for (j = 0 ; j <= i; j ++)
   {
   printf("tab_sequence_easy[%d] : %d\n", j, tab_sequence_easy[j]);
   if(tab_sequence_easy[j] == 1 )
   digitalWrite(led_A, HIGH); 
   else if (tab_sequence_easy[j] == 2 )
   digitalWrite(led_B, HIGH);
   else if (tab_sequence_easy[j] == 3 )
   digitalWrite(led_C, HIGH);
   else if (tab_sequence_easy[j] == 4 )
   digitalWrite(led_D, HIGH);
   else
   reset_leds() ;
   delay(500);
   reset_leds() ;
   delay(500);
   }
   printf("** END SEQUENCE**\n\n") ;
   }    
   printf("\n") ;
   */
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
  //delay(1000) ;
}














