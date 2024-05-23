#include <Arduino.h>

#define DO 523 // Definimos la frecuencia de cada nota musical    -C
#define RE 587 //D
#define MI 659 //E
#define FA 698 //F
#define SOL 784 //G
#define LA 880 //A
#define SI 988 //B
#define DOs 1047 //D#
#define Buzzpin 13 // Definimos el pin al que conectamos el zumbador

void setup() {
}

void loop() {
   tone(Buzzpin,SOL); // Mediante la función tone() indicamos el pin de salida y la frecuencia de la señal cuadrada
   delay(1000); // Retraso de 300 ms para fijar la duración de la nota
   tone(Buzzpin,DOs); // Repetimos para cada nota creando la escala musical
   delay(200);
   tone(Buzzpin,SOL);
   delay(500);
   tone(Buzzpin,LA);
   delay(300);
   tone(Buzzpin,SI);
   delay(100);
   tone(Buzzpin,MI);
   delay(500);
   tone(Buzzpin,MI);
   delay(300);
   tone(Buzzpin,LA);
   delay(300);
   tone(Buzzpin,SOL);
   delay(400);
   tone(Buzzpin,FA);
   delay(300);
   tone(Buzzpin,SOL);
   delay(300);
    tone(Buzzpin,DO);
   delay(300);
    tone(Buzzpin,DO);
   delay(300);
    tone(Buzzpin,RE);
   delay(300);
    tone(Buzzpin,RE);
   delay(300);
    tone(Buzzpin,MI);
   delay(300);
    tone(Buzzpin,FA);
   delay(300);
 tone(Buzzpin,FA);
   delay(300);
 tone(Buzzpin,SOL);
   delay(300);
 tone(Buzzpin,LA);
   delay(300);
    tone(Buzzpin,SI);
   delay(300);
    tone(Buzzpin,LA);
   delay(300);
    tone(Buzzpin,DOs);
   delay(300);




   noTone(Buzzpin); // Detenemos la generación de la señal cuadrada
   delay(300);      // durante 300 ms
}
