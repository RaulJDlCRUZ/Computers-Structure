/*EJEMPLO DE LOS INFRARROJOS PERO ECOBOT AVANZA SI ALGUNO DE LOS SENSORES ES 0*/
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define IR_left 2 // Sensor IR izquierdo conectado al pin digital 2
#define IR_right 3 // Sensor IR derecho conectado al pin digital 3

#define DOs 1047 //C# PITIDO
#define Buzzpin 13 // Definimos el pin al que conectamos el zumbador

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  320 // Valor de la longitud mínima del pulso PWM para velocidad máxima en sentido antihorario (valor de 0 a 4096).
#define SERVOSTOP 380 // Valor de la longitud del pulso para dentener el servo (valor de 0 a 4096).
#define SERVOMAX  440 // Valor de la longitud máxima del pulso PWM para velocidad máxima en sentido horario (valor de 0 a 4096).
#define servo_left 0  // Servo izquierdo conectado al canal 0 del PWM shield.
#define servo_right 1  // Servo derecho conectado al canal 1 del PWM shield.

void setup() {
  pinMode(IR_left,INPUT);  // Configuramos el pin 2 donde se conectan los sensor IR izquierdo como INPUT
  pinMode(IR_right,INPUT);  // Configuramos el pin 3 donde se conectan los sensor IR izquierdo como INPUT
  Serial.begin(9600); // Inicializamos la comunicación serie a 9600 baudios
  pwm.begin();
  pwm.setPWMFreq(60);  // Frecuencia PWM fijada en 60 Hz.
}

void loop() {
  int valor_IR_left = digitalRead(IR_left); // Leemos la entrada digital 0 donde está conectado el sensor IR izquierdo
  int valor_IR_right = digitalRead(IR_right); // Leemos la entrada digital 1 donde está conectado el sensor IR derecho

  Serial.print("IR_left: "); // Imprime el texto "IR_left: " 
  Serial.print(valor_IR_left); // Imprime el valor del sensor IR izquierdo
  Serial.print("\t"); // Imprime una tabulación   
  Serial.print("IR_right: "); // Imprime el texto "IR_right: "  
  Serial.println(valor_IR_right); // Imprime el valor del sensor IR derecho 
  
do{
    pwm.setPWM(servo_left, 0, SERVOSTOP);
    pwm.setPWM(servo_right, 0, SERVOSTOP);
    valor_IR_left = digitalRead(IR_left);
    valor_IR_right = digitalRead(IR_right);
}while(valor_IR_left==1 || valor_IR_right==1);

  do{
    pwm.setPWM(servo_left, 0, SERVOMIN);
    pwm.setPWM(servo_right, 0, SERVOMAX);
    valor_IR_left = digitalRead(IR_left);
    valor_IR_right = digitalRead(IR_right);
  }while(valor_IR_left==0 && valor_IR_right==0);
  
  delay(100); // Retraso entre lecturas de 100 ms
}