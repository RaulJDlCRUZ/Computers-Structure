#include <Arduino.h>

static int a;

void setup(){
  Serial.begin(9600);

  int b; 
  int* a_dir = &a;
  int* b_dir = &b;
  char text[64];
  b = 1587879870; 
  sprintf(text, "Direccion de a: %x\nDireccion de b: %x\n", &a, &b);
  Serial.print(text);
}

void loop(){
}
