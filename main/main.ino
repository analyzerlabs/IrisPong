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

byte corazon[8] =
{
0b00000,
0b00000,
0b01010,
0b11111,
0b11111,
0b01110,
0b00100,
0b00000
};

void setup(){
    lcd.begin(16, 2);
    lcd.setCursor(0,1);
    lcd.print("Iris Pong");
    lcd.setCursor(1,1);
    lcd.print("By AnalyzerLabs");
}

void loop(){
    delay(1000)

}