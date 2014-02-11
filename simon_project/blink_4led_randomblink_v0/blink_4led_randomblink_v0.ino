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

// the setup routine runs once when you press reset:
void setup() {                
  Serial.begin(9600) ;
  // initialize the digital pin as an output.
  pinMode(led_A, OUTPUT);     
  pinMode(led_B, OUTPUT);     
  pinMode(led_C, OUTPUT);     
  pinMode(led_D, OUTPUT);
}

void reset_leds() {
  digitalWrite(led_A, LOW);
  digitalWrite(led_B, LOW);  
  digitalWrite(led_C, LOW);
  digitalWrite(led_D, LOW);
}

// the loop routine runs over and over again forever:
void loop() {

  reset_leds() ;  
  delay(500);

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
  

}


