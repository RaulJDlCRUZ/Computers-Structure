#include <Arduino.h>

#define button_pin 11
  
void setup() {
  Serial.begin(9600);
  pinMode(button_pin, INPUT);
}
 
void loop(){
  int button_value = digitalRead(button_pin);
 
  if (button_value == HIGH) {
      Serial.println("Pressed");
  }
  else {
      Serial.println("Not pressed");
  }
  delay(1000);
}