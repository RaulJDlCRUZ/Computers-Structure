#include <Arduino.h>

#define red_led 12
#define green_led 9
#define Buzzpin 13
#define button_pin 11
#define DOs 1047
volatile bool alarm_on = true;

void blink() {
  tone(Buzzpin,DOs);
  digitalWrite(red_led, HIGH);   
  digitalWrite(green_led, HIGH);   
  delay(1000);                       
  
  digitalWrite(red_led, LOW);    
  digitalWrite(green_led, LOW);    
  noTone(Buzzpin);
  delay(1000);                
}

void switch_alarm_state() {
  alarm_on = !alarm_on;
}

void setup() {
  Serial.begin(9600); 
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(button_pin), switch_alarm_state, RISING);
}

void loop() {
  int light = analogRead(A0); 
  
  if(light > 50 && alarm_on){
    blink();
  }else{
    delay(200);
  }

  Serial.print("\nLight: "); 
  Serial.print(light); 
  Serial.print("\nAlarm state: "); 
  Serial.print(alarm_on); 
}