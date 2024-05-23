#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  320 // Valor de la longitud mínima del pulso PWM para velocidad máxima en sentido antihorario (valor de 0 a 4096).
#define SERVOSTOP 380 // Valor de la longitud del pulso para dentener el servo (valor de 0 a 4096).
#define SERVOMAX  440 // Valor de la longitud máxima del pulso PWM para velocidad máxima en sentido horario (valor de 0 a 4096).
#define servo_left 0  // Servo izquierdo conectado al canal 0 del PWM shield.
#define servo_right 1  // Servo derecho conectado al canal 1 del PWM shield.

/***   Declaración de las funciones setup y loop   ***/
void setup(){
  pwm.begin();
  pwm.setPWMFreq(60);  // Frecuencia PWM fijada en 60 Hz.
}

void loop(){
  // Avanzamos hacia delante
  pwm.setPWM(servo_left, 0, SERVOMIN);
  pwm.setPWM(servo_right, 0, SERVOMAX);   
}