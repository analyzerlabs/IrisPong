/*  Software wrote for Arduino Mega by Analyzerlabs
    version: 1.0
    authon: Miguel Quispe
    email: fisicomiguel@gmail.com / miguelquispecastro@uni.pe
    telf:  +51 947166490

 Lima, November 2019
*/
#include <Servo.h>    //incluimos la libreria del servo aun no funciona
#include <LiquidCrystal.h>   //incluimos la libreria de LCD16X2
#include "SHCSR04.h"    //incluimos la libreria del sensor HCSR04 aun no funciona
#include "variables.h"  //incluimos las variables
#include "sensor.h"   // incluimos las funcioones para el sensor aun on funciona
#include "move.h"   //imcluimos las funciones para el movimiento aun no funciona
#include "lcd.h"   //incluimos las funciones generadas para la pantalla

void setup() {
  Serial.begin(9600);      //iniciamos una conexcion serial para el debugeo
  pinMode(interruptPin, INPUT);   // asignamos al pin 19 como iterrupcion para el pulsador
  lcdInit();                       // llamamos a la funicon lcdInit creado en el otro apartado
  sensorInit(20);                  // llamamos a la funcion sensorInit creado en el otro apartado
  menuInicio();         //llamamos a la funcion menuInicio creado en el otro apartado
}

void loop() {
  menuJuego();    //llamamos a al funcion menuJuego creado para la pantalla LCD
  game();           //llamamos a al funcion game creado para la pantalla LCD
}
