#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm= Adafruit_PWMServoDriver();

#define IR_left 2
#define IR_right 3

#define SERVOMIN 320
#define SERVOMAX 440
#define SERVOSTOP 380

#define servo_left 0
#define servo_right 1

#define red_led 12
#define green_led 9

#define buzzpin 13
#define NOTA 523

#define button_pin 11
volatile bool alarm_on = true;

void switch_alarm_state() {
alarm_on = !alarm_on;
}
void setup() {
  attachInterrupt(digitalPinToInterrupt(button_pin), switch_alarm_state, RISING);
  pinMode(IR_left, INPUT);
  pinMode(IR_right, INPUT);
  Serial.begin(9600);
  pinMode(button_pin,INPUT);
  pwm.begin();
  pwm.setPWMFreq(60);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
}

void loop() {
 int valoriz = digitalRead(IR_left);
 int valorder = digitalRead(IR_right);
 int button_value= digitalRead(button_pin);

 if(valoriz==1 && valorder ==1){
   noTone(buzzpin);
   digitalWrite(red_led, LOW);
   digitalWrite(green_led, HIGH);
   pwm.setPWM(servo_left, 0, SERVOMIN);
   pwm.setPWM(servo_right, 0, SERVOMAX);
 }
 if(valoriz==0 && valorder ==0){
   digitalWrite(green_led, LOW);
   digitalWrite(red_led, HIGH);
   tone(buzzpin,NOTA);
   pwm.setPWM(servo_left, 0, SERVOMIN);
   pwm.setPWM(servo_right, 0, SERVOMAX);
 }
 if(button_value==HIGH){
   noTone(buzzpin);
   digitalWrite(red_led, LOW);
   digitalWrite(green_led, LOW);
   pwm.setPWM(servo_left, 0, SERVOMIN);
   pwm.setPWM(servo_right, 0, SERVOSTOP);
   delay(3000);
 }
}