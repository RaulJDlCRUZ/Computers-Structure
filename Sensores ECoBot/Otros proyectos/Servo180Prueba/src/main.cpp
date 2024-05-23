#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
/*desde 45 grados a 135 ===== 300 a 540*/
#define SERVOMIN 320
#define SERVOSTOP 380
#define SERVOMAX 440
#define servo_left 0
#define servo_right 1
void setup() {
  pwm.begin();
  pwm.setPWMFreq(60);
  pwm.setPWM(servo_left, 0, SERVOSTOP);
  pwm.setPWM(servo_right, 0, SERVOSTOP);

}

void loop() {
  pwm.setPWM(servo_left, 0, SERVOSTOP);
pwm.setPWM(servo_right, 0, SERVOSTOP);
  for(int i=300;i<451;i++){
    pwm.setPWM(2, 0, i); //PIN SERVO =2
   delay(10);
  }
  delay(1000);
  for(int i=450;i>299;i--){
    pwm.setPWM(2, 0, i); //PIN SERVO =2
   delay(10);
  }
}