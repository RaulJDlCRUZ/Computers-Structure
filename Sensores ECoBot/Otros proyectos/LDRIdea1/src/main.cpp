#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#define Buzzpin 13
#define DOs 1047 //C# PITIDO

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  320
#define SERVOSTOP 380 
#define SERVOMAX  440 
#define servo_left 0 
#define servo_right 1 

void setup() {
  Serial.begin(9600); // Inicializamos la comunicación serie a 9600 baudios
  pinMode(9,OUTPUT);//LED VERDE SALIDA
  pinMode(12,OUTPUT);//LED ROJO SALIDA
  pwm.begin();
  pwm.setPWMFreq(60);  // Frecuencia PWM fijada en 60 Hz.
}

void loop() {
  pwm.setPWM(servo_left, 0, SERVOMIN);
  pwm.setPWM(servo_right, 0, SERVOMAX);
  digitalWrite(9,LOW);
  digitalWrite(12,LOW);
  noTone(Buzzpin);
  int light = analogRead(A0); // Leemos la entrada analógica 0 donde está conectado el sensor de luz izquierdo
  Serial.print("\nLight: "); // Imprime el texto "Light_left: "
  Serial.print(light); // Imprime el valor del sensor de luz izquierdo
  if(light<300){
    pwm.setPWM(servo_left, 0, SERVOMIN);
    pwm.setPWM(servo_right, 0, SERVOMAX);
    digitalWrite(12,HIGH);
    light=analogRead(A0);
    if(light<200){
    pwm.setPWM(servo_left, 0, SERVOSTOP);
    pwm.setPWM(servo_right, 0, SERVOSTOP);
      digitalWrite(9,HIGH);
      light=analogRead(A0);
      if(light<100){
        pwm.setPWM(servo_left, 0, SERVOSTOP);
        pwm.setPWM(servo_right, 0, SERVOSTOP);
        tone(Buzzpin, DOs);
        light=analogRead(A0);
      }
    }
  }
  delay(200); // Retraso entre lecturas de 200 ms
}