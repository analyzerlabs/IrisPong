void calibratorInit(){
    pinMode(calibrationPin,INPUT);
  }
  
void calibrate(){
    boolean aux = digitalRead(20);   // lee el pin del boton
    digitalWrite(dirPin,LOW);
    while(calibrationFlag == true){
          if(digitalRead(20)==false && aux == true)calibrationFlag = !calibrationFlag; //si hay cambio sale
          digitalWrite(stepPin,HIGH);
          delay(1);
          digitalWrite(stepPin,LOW);
          delay(1);
          Serial.println("calibrando");
      }
  }
