/*  Software wrote for Arduino Mega by Analyzerlabs
    version: 1.0
    authon: Miguel Quispe
    email: fisicomiguel@gmail.com / miguelquispecastro@uni.pe
    telf:  +51 947166490

 Lima, November 2019
*/
#include <Servo.h>
#include <LiquidCrystal.h>
#include <HCSR04.h>
#include "move.h"



void setup() {
  LcdInit();
  SensorInit();
  menuInicio();
}
int distance=0;
void loop() {
  distance = distanceSensor.measureDistanceCm();
  showDistance(distance);
  if(distance < 15)StepMotor(1,1); //si la distncia qes menor a 15 entonces el motor se cuenta 1 pelota
  else StepMotor(0,1);   
}
