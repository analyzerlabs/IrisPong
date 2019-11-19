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
#include "variables.h"  //incluir las librerias en orden 
#include "sensor.h"   // puesto que algunas variables que utilizan unas estan en otras
#include "move.h"
#include "lcd.h"

void setup() {
  Serial.begin(9600);
  pinMode(interruptPin, INPUT);
  lcdInit();
  sensorInit(20); // Inicia la distancia de deteccion en cm
  menuInicio();
}

void loop() {
  menuJuego();
  game();
}
