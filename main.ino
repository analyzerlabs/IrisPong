#include <Servo.h>
#include <LiquidCrystal.h>
#include "move.cpp"

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