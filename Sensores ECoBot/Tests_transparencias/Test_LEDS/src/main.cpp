#include <Arduino.h>

#define red_led 12
#define green_led 9

void setup() {
  // initialize digital pin left_led as an output.
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(red_led, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(green_led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  
  digitalWrite(red_led, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(green_led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}