#include <Arduino.h>
/*
void setup() {
Serial.begin(9600);
}
void loop(){
int contador=0;
for(int i=0;i<10;i++) contador=contador+i;
}
*/
void setup(){
    Serial.begin(9600);
    }

void loop(){
    Serial.print("Hello, world");
    delay(1000);
}


/*static int a;

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
}*/

