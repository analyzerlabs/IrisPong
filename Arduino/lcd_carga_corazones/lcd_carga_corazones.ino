#include <LiquidCrystal.h>
#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(8, 9);
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

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

void setup() {
  lcd.begin(16, 2); //Inicializa la pantalla LCD 16x2 CARACTERES
  lcd.createChar(0, corazon);
  pinMode(20,OUTPUT);
  pinMode(21,OUTPUT);
  menuInicio();
}
int distance=0;
void loop() {
  distance = distanceSensor.measureDistanceCm();
  showDistance(distance);
  if(distance < 15)StepMotor(1,1); // condicion si la distncia que mide el sensor es menor a 15 entonces el motor se mueve
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
