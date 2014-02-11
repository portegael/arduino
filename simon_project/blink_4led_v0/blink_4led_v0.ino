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

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led_A, OUTPUT);     
  pinMode(led_B, OUTPUT);     
  pinMode(led_C, OUTPUT);     
  pinMode(led_D, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led_D, LOW);
  digitalWrite(led_C, LOW);  
  digitalWrite(led_B, LOW);
  digitalWrite(led_A, HIGH);
  delay(1000);              

  digitalWrite(led_A, LOW);
  digitalWrite(led_D, LOW);  
  digitalWrite(led_C, LOW);
  digitalWrite(led_B, HIGH);
  delay(1000);
  
  digitalWrite(led_B, LOW);
  digitalWrite(led_A, LOW);  
  digitalWrite(led_D, LOW);
  digitalWrite(led_C, HIGH);
  delay(1000);
  
  digitalWrite(led_A, LOW);
  digitalWrite(led_B, LOW);  
  digitalWrite(led_C, LOW);
  digitalWrite(led_D, HIGH);
  delay(1000);
  
}
