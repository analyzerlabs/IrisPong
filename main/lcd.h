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
  lcd.print("---Iris Pong----");  // mensaje de inicio
  for(int i=0 ; i<16;i++){     //carga de corazones en pantalla
    lcd.setCursor(i,1);
    lcd.write(byte(0));   
    delay(100);
  }
  delay(500);                 //espera 0.5 segundos
}

void menuJuego(){
  boolean aux = digitalRead(19);   // lee el pin del boton
  while(control == true){          //si no se detecta cambio se queda en el while
    if(digitalRead(19)==false && aux == true)control = !control; //si hay cambio sale    
    lcd.setCursor(0,0);               // imprime Iniciar juego hasta que se oprima el boton
    lcd.print("---Iris Pong----");
    lcd.setCursor(0,1);
    lcd.print(" Iniciar Juego  ");
  }
}

void game(){
   lcd.setCursor(0,0);
   lcd.print("INICIANDO JUEGO ");
   lcd.setCursor(0,0);
   lcd.print("                ");
   wait(1500);
   lcd.setCursor(0,1);
   lcd.print("  PREPARADOS ?  ");
   wait(1000);
   lcd.setCursor(0,1);
   lcd.print("     LISTOS ?   ");
   wait(1000);
   lcd.setCursor(0,1);
   lcd.print("     YA !!!!    ");
   wait(500);
   lcd.setCursor(0,1);
   lcd.write(byte(7));   
   t=millis();
   int n = 0;
   boolean i=0;
   int pelotas = 0;
   while((30-(millis()-t)/1000) > 0){    //bucle de inicio de juego pr 30 seg
      if(readSensor())pelotas++;
      wait(80);   //tiempor para lectura de pelotas adecuada
      StepMotor();  // se mueve el motor 
      if((millis()-t)>1000*n){           //condicion cada segundo de los 30 seg
         Serial.println(millis());
         n++;                            //retroalimenta la condicion
         unsigned long t_restante = 30 - (millis()-t)/1000;     //calcula el tiempo restante
         if(t_restante >= 10)lcd.setCursor(2,1);   //condifciones para imprimir numeros
         if(t_restante < 10){                      //que cambian de 2 a 1 digito en lcd
            lcd.setCursor(2,1);                           
            lcd.print(" ");
            lcd.setCursor(3,1);
         }
         lcd.print(t_restante);     // imprime el tiempo restante
         lcd.setCursor(2,0);
         lcd.print(pelotas);
         lcd.setCursor(4,0);
         lcd.print("        ");
         i = !i;                    // cambia el simbolo reloj
         lcd.setCursor(0,1);        // posciona el simbolo reloj
         lcd.write(byte(6+int(i)));  // imprime el simbolo reloj en LCD con movimiento
         lcd.print(":");
         lcd.setCursor(0,0);        // posciona el simbolo pong
         lcd.write(byte(4+int(i)));  // imprime el simbolo pong en LCD con movimiento
         lcd.print(":");
      }
   }
   lcd.setCursor(0,0);        // mensaje final
   lcd.print("YOU LOSE");
   for(int i =0; i<16;i++){  
       lcd.setCursor(i,1);        
       lcd.write(byte(3));
       delay(750); 
   }
   delay(2000);
   control = ! control;        //variable de control de juego para reiniciar
}
void lcdInit(){
  lcd.begin(16, 2); //Inicializa la pantalla LCD 16x2 CARACTERES
  lcd.createChar(0, heart);
  lcd.createChar(1, R1);
  lcd.createChar(2, R2);
  lcd.createChar(3, sad);
  lcd.createChar(4, pong1);
  lcd.createChar(5, pong2);
  lcd.createChar(6, reloj1);
  lcd.createChar(7, reloj2);
  menuInicio();
}
