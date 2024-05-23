#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVO_45deg  300 // Servo a 45º (sensor de ultrasonido mirando hacia la derecha).
#define SERVO_90deg 420 // Servo a 90º (sensor de ultrasonido mirando hace delante).
#define SERVO_135deg  540 // Servo a 1355º (sensor de ultrasonido mirando hacia la izquierda).

/***   Variables Globales   ***/
const int servo_180 = 2; // Servo conectado al canal 2 del PWM shield.

/***   Declaración de las funciones setup y loop   ***/
void setup()
{
  pwm.begin();
  pwm.setPWMFreq(60);  // Frequencia PWM fijada a 60 Hz
}

void loop()
{
  // Posición 45º
  pwm.setPWM(servo_180, 0, SERVO_45deg);
  delay(2000);

  // Posición 90º
  pwm.setPWM(servo_180, 0, SERVO_90deg);
  delay(2000);
  
  // Posición 135º
  pwm.setPWM(servo_180, 0, SERVO_135deg);
  delay(2000);
}