const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
UltraSonicDistanceSensor distanceSensor(8, 9);
const byte interruptPin = 19;
boolean control = true;
int distance=0;
unsigned long t=0;
byte heart[8] =
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

byte R1[8] =
{
0b11111,
0b11111,
0b11111,
0b11111,
0b11111,
0b11111,
0b11111,
0b11111,
};

byte R2[8] =
{
0b01111,
0b01111,
0b01111,
0b01111,
0b01111,
0b01111,
0b01111,
0b01111,
};

byte sad[8] =
{
0b00000,
0b01010,
0b01010,
0b00000,
0b00000,
0b01110,
0b00001,
0b00000,
};

byte pong1[8] =
{
0b00000,
0b00000,
0b01110,
0b11111,
0b11111,
0b11111,
0b01110,
0b00000,
};

byte pong2[8] =
{
0b00000,
0b01110,
0b11111,
0b11111,
0b11111,
0b01110,
0b00000,
0b00000,
};

byte reloj1[8] =
{
0b11111,
0b10001,
0b01110,
0b00100,
0b01010,
0b10001,
0b10001,
0b11111,
};

byte reloj2[8] =
{
0b11111,
0b10001,
0b01110,
0b00100,
0b01010,
0b10001,
0b11111,
0b11111,
};

void wait(int tiempo){
  unsigned long T = millis();
  while(millis()<T+tiempo){}
}
