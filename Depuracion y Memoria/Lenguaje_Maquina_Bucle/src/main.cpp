#include <Arduino.h>

void setup(){
  Serial.begin(9600);
}

void loop(){
  int contador = 0;
  for (int i = 0; i < 10; i++){
    contador = contador + i;
  }
}
