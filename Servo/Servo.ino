#include <ESP32Servo.h>

Servo servo;
int pinServo = 2;


void setup() 
{
  //Inicializar la posicion del servo
  servo.attach(pinServo,500,2500);
}

//Inicializar la posicion (en grados) del sevo
int pos = 0;

void loop() {
  
  //Ciclo que posicionara el servo de 0 a 180
  for (pos = 0; pos <= 180; pos = pos + 1)
  {
    servo.write(pos);
    delay(15);
  }
  
  //Ciclo que posicionara el servo de 180 a 0
  for (pos = 180; pos >= 0; pos = pos - 1)
  {
    servo.write(pos);
    delay(15);
  }
}
