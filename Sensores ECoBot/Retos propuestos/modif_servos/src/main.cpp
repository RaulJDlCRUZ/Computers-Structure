#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  320
#define SERVOSTOP 380
#define SERVOMAX  440
#define servo_left 0
#define servo_right 1

void setup(){
  pwm.begin();
  pwm.setPWMFreq(60); 
}

void loop(){
  // Avanzamos hacia delante durante 4 segundos.
  pwm.setPWM(servo_left, 0, SERVOMIN);
  pwm.setPWM(servo_right, 0, SERVOMAX);      
  delay(4000);

  // Detenemos los servos durante 4 segundos.
  pwm.setPWM(servo_left, 0, SERVOSTOP);
  pwm.setPWM(servo_right, 0, SERVOSTOP);
  delay(4000);

  // Rotamos hacia la derecha durante 2 segundos.
  pwm.setPWM(servo_left, 0, SERVOMIN);
  pwm.setPWM(servo_right, 0, SERVOMIN);      
  delay(2000);

  // Rotamos hacia la izquierda durante 2 segundos.
  pwm.setPWM(servo_left, 0, SERVOMAX);
  pwm.setPWM(servo_right, 0, SERVOMAX);      
  delay(2000);
  
  // Avanzamos hacia atrás durante 4 segundos.
  pwm.setPWM(servo_left, 0, SERVOMAX);
  pwm.setPWM(servo_right, 0, SERVOMIN);      
  delay(4000);
}
