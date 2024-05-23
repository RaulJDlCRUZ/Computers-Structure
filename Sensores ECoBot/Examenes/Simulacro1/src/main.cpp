#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  320 // Valor de la longitud mí­nima del pulso PWM para velocidad máxima en sentido antihorario (valor de 0 a 4096).
#define SERVOSTOP 380 // Valor de la longitud del pulso para dentener el servo (valor de 0 a 4096).
#define SERVOMAX  440 // Valor de la longitud máxima del pulso PWM para velocidad máxima en sentido horario (valor de 0 a 4096).
#define servo_left 0  // Servo izquierdo conectado al canal 0 del PWM shield.
#define servo_right 1  // Servo derecho conectado al canal 1 del PWM shield.

#define DOs 1047 //C# PITIDO
#define Buzzpin 13 // Definimos el pin al que conectamos el zumbador

#define ledverde 9

/*METODO PARA LA EXCEPTION DEL BOTON*/
volatile bool alarm_on = true;
void switch_alarm_state() {
alarm_on = !alarm_on;}

/***   Declaracion de las funciones setup y loop   ***/
void setup(){
  pwm.begin();
  pwm.setPWMFreq(60);  // Frecuencia PWM fijada en 60 Hz.
  pinMode(12,OUTPUT); //led rojo
  pinMode(ledverde,OUTPUT); //led verde
  pinMode(11,INPUT); //boton
  attachInterrupt(digitalPinToInterrupt(11), switch_alarm_state, RISING); //EXCEPTION PARA QUE LEA
}

void loop(){

  // PRIMERA PARTE. INICIALMENTE SE MUEVE HACIA LA DERECHA, Y LED ROJO ENCENDIDO
  
  do{
  noTone(Buzzpin);
  digitalWrite(ledverde,LOW);
  digitalWrite(12,HIGH);
  pwm.setPWM(servo_left, 0, SERVOMIN); //Pin del PWM, 0, ANTIHORARIO PARA LA RUEDA DE LA IZQUIERDA (HACER EL MOVIMIENTO CON LOS DEDOS PARA ENTENDER)
  pwm.setPWM(servo_right, 0, SERVOSTOP);
  }while(alarm_on);
//AHORA SI PULSO EL BOTON SE PARA Y ENCIENDE VERDE
  do{
    tone(Buzzpin,DOs);
    pwm.setPWM(servo_left, 0, SERVOSTOP);
    pwm.setPWM(servo_right, 0, SERVOSTOP);
    digitalWrite(12,LOW);
    digitalWrite(ledverde,HIGH);
  }while(!alarm_on);
//LO PULSO DE NUEVO, SIGUE
  do{
  noTone(Buzzpin);
  digitalWrite(ledverde,LOW);
  digitalWrite(12,HIGH);
  pwm.setPWM(servo_left, 0, SERVOSTOP); //Pin del PWM, 0, ANTIHORARIO PARA LA RUEDA DE LA IZQUIERDA (HACER EL MOVIMIENTO CON LOS DEDOS PARA ENTENDER)
  pwm.setPWM(servo_right, 0, SERVOMAX);
  }while(alarm_on);
//BUCLE....
  do{
    tone(Buzzpin,DOs);
    pwm.setPWM(servo_left, 0, SERVOSTOP);
    pwm.setPWM(servo_right, 0, SERVOSTOP);
    digitalWrite(12,LOW);
    digitalWrite(ledverde,HIGH);
  }while(!alarm_on);

}