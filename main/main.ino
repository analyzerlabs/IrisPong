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

void showDistance(int d){
  lcd.setCursor(0,0);
  lcd.print("---Iris Pong----");
  lcd.setCursor(0, 1);
  lcd.println("D = ");
  lcd.setCursor(4, 1);
  lcd.println(d);
  lcd.setCursor(9, 1);
  lcd.println(" cm    ");

}
void StepMotor(int d,int v){
  digitalWrite(21,d);
  for(int i=0;i<200*v;i++){
      digitalWrite(20,HIGH);
      delay(1);
      digitalWrite(20,LOW);
      delay(1);
    }
}

void menuInicio(){
  lcd.setCursor(0,0);
  lcd.print("---Iris Pong----");
  for(int i=0 ; i<16;i++){
    lcd.setCursor(i,1);
    lcd.write(byte(0));   
    delay(1000);
  }
  delay(5000);
}
