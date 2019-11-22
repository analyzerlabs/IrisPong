void menuInicio(){       //funcion para mostrar el menu de inicio
  lcd.setCursor(0,0);
  lcd.print("---Iris Pong----");  // mensaje de inicio
  for(int i=0 ; i<16;i++){     //carga de corazones en pantalla
    lcd.setCursor(i,1);        
    lcd.write(byte(0));   
    delay(100);
  }
  delay(500);                 //espera 0.5 segundos
}

//  -----------------------------------------------------------------//
 //  Creamos la funcion Menu para la pantalla LCD16X2
 //  -----------------------------------------------------------------//
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
//  -----------------------------------------------------------------//
 //  Creamos la funcion Iniciar Juego para la pantalla LCD16X2
 //  ----------------------------------------------------------------//
void game(){
   lcd.setCursor(0,0);                        //mueve el cursos a la columna 0 de la fila 0
   lcd.print("INICIANDO JUEGO ");             //imprime "Iniciando Juego"
   lcd.setCursor(0,0);
   lcd.print("                ");
   wait(1500);
   lcd.setCursor(0,1);                  //mueve el cursos a la columna 0 de la fila 1
   lcd.print("  PREPARADOS ?  ");       // imprime PREPARADOS?
   wait(1000);
   lcd.setCursor(0,1);                //mueve el cursos a la columna 0 de la fila 1
   lcd.print("     LISTOS ?   ");     // imprime LISTOS?
   wait(1000);
   lcd.setCursor(0,1);                //mueve el cursos a la columna 0 de la fila 1
   lcd.print("     YA !!!!    ");     // imprime YA!!!
   wait(500);
   lcd.setCursor(0,1);                //mueve el cursos a la columna 0 de la fila 1
   lcd.write(byte(7));                //imprime el icono pelota
   t=millis();
   int n = 0;
   boolean i=0;
   pelotas=0;
   while((30-(millis()-t)/1000) > 0){    //bucle de inicio de juego pr 30 seg
      readSensor();
      
      StepMotor();  // se mueve el motor 
      if((millis()-t)>500*n){           //condicion cada segundo de los 30 seg
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
       lcd.write(byte(3));   //imprime el icono cara triste
       delay(750); 
   }
   delay(2000);
   control = ! control;        //variable de control de juego para reiniciar
}
 //  -----------------------------------------------------------------//
 //  Creamos la Funcion de Inicio de la Pantalla LCD 16X2
 //  -----------------------------------------------------------------//
void lcdInit(){
  lcd.begin(16, 2); //Inicializa la pantalla LCD 16x2 CARACTERES
  lcd.createChar(0, heart);      //se genera el caracter corazon
  lcd.createChar(1, R1);
  lcd.createChar(2, happy);    //se genera el caracter carita feliz
  lcd.createChar(3, sad);       //se genera el caracter carita triste
  lcd.createChar(4, pong1);    //se genera el caracter pelota arriba
  lcd.createChar(5, pong2);    //se genera el caracter pelota abajo
  lcd.createChar(6, reloj1);    //se genera el caracter reloj de arena lleno
  lcd.createChar(7, reloj2);    //se genera el caracter reloj de arena vacio
  menuInicio();                 //se llama a la funcion menu inicio
}
