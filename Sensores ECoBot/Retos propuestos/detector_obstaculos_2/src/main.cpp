#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  320 // Valor de la longitud mínima del pulso PWM para velocidad máxima en sentido antihorario (valor de 0 a 4096).
#define SERVOSTOP 380 // Valor de la longitud del pulso para dentener el servo (valor de 0 a 4096).
#define SERVOMAX  440 // Valor de la longitud máxima del pulso PWM para velocidad máxima en sentido horario (valor de 0 a 4096).
#define servo_left 0  // Servo izquierdo conectado al canal 0 del PWM shield.
#define servo_right 1  // Servo derecho conectado al canal 1 del PWM shield.
#define pingPin 5
#define Buzzpin 13 //Definimos zumbador a pin 13
#define Do 523 // Tono Do sostenido
volatile long duration;

volatile bool suena = false;

long calcular_distancia(){
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(10);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  return duration / 29 / 2;
}
void setup() {
  pwm.begin();
  pwm.setPWMFreq(60);
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  
  long cm=calcular_distancia();
  if(cm>20){
    Serial.println("if");
    noTone(Buzzpin);
    pwm.setPWM(servo_left, 0, SERVOMIN);
    pwm.setPWM(servo_right, 0, SERVOMAX);
  }else if(cm>10 && cm<20){
    Serial.println("elif");
    pwm.setPWM(servo_left, 0, SERVOMIN);
    pwm.setPWM(servo_right, 0, SERVOMAX);
    tone(Buzzpin, Do);
    delay(200);
    noTone(Buzzpin);
  }else{
    Serial.println("else");
    pwm.setPWM(servo_left, 0, SERVOSTOP);
    pwm.setPWM(servo_right, 0, SERVOMAX);
    tone(Buzzpin, Do);

    // if(suena == false){
    //   Serial.println(suena);
    //   tone(Buzzpin, Do);
    //   suena = true;
    // }
  }
}
