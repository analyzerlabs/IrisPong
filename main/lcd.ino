void LcdInit(){
  lcd.begin(16, 2); //Inicializa la pantalla LCD 16x2 CARACTERES
  lcd.createChar(0, heart);
  lcd.createChar(0, A);
  menuInicio();
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
