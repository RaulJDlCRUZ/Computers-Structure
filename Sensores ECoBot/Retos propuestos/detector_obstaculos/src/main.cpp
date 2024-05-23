#include <Arduino.h>

#define pingPin 5
#define DOs 1047
#define Buzzpin 13

long read_ultrasonic(){
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(10);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  long duration = pulseIn(pingPin, HIGH);

  return duration / 29 / 2;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  long cm = read_ultrasonic();

  if(cm <= 30){
    tone(Buzzpin,DOs);
  }else{
    noTone(Buzzpin);
  }

  Serial.print(cm);
  Serial.println();

  delay(100);
}