#include <Arduino.h>

void setup() {
  Serial.begin(9600); // Inicializamos la comunicación serie a 9600 baudios
}

void loop() {
  int light = analogRead(A0); // Leemos la entrada analógica 0 donde está conectado el sensor de luz izquierdo
  Serial.print("\nLight: "); // Imprime el texto "Light_left: "
  Serial.print(light); // Imprime el valor del sensor de luz izquierdo

  delay(200); // Retraso entre lecturas de 200 ms
}