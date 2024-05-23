#include <Arduino.h>

/*
El valor 0 indica que el sensor IR detecta color negro y el led del zum bloq sensor IR se enciende.
El valor 1 indica que el sensor IR detecta color blanco y el led del zum bloq sensor IR se apaga.
*/

#define IR_left 2 // Sensor IR izquierdo conectado al pin digital 2
#define IR_right 3 // Sensor IR derecho conectado al pin digital 3

void setup() {
  pinMode(IR_left,INPUT);  // Configuramos el pin 2 donde se conectan los sensor IR izquierdo como INPUT
  pinMode(IR_right,INPUT);  // Configuramos el pin 3 donde se conectan los sensor IR izquierdo como INPUT
  Serial.begin(9600); // Inicializamos la comunicación serie a 9600 baudios
}

void loop() {
  int valor_IR_left = digitalRead(IR_left); // Leemos la entrada digital 0 donde está conectado el sensor IR izquierdo
  int valor_IR_right = digitalRead(IR_right); // Leemos la entrada digital 1 donde está conectado el sensor IR derecho

  Serial.print("IR_left: "); // Imprime el texto "IR_left: "
  Serial.print(valor_IR_left); // Imprime el valor del sensor IR izquierdo

  Serial.print("\t"); // Imprime una tabulación
  Serial.print("IR_right: "); // Imprime el texto "IR_right: "

  Serial.println(valor_IR_right); // Imprime el valor del sensor IR derecho
  delay(100); // Retraso entre lecturas de 100 ms
}