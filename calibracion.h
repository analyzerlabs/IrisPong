void calibratorInit(){
    pinMode(calibrationPin,INPUT);
    
  }
  
void calibrate(){
    boolean aux = digitalRead(20);   // lee el pin del boton
    digitalWrite(dirPin,LOW);
    while(calibrationFlag == true){
          if(digitalRead(20)==false && aux == true)calibrationFlag = !calibrationFlag; //si hay cambio sale
          digitalWrite(stepPin,HIGH);
          delay(5);
          digitalWrite(stepPin,LOW);
          delay(1);
          angle-- ;
          if(angle < 0)angle= 0;
          irisOpen(angle);
          Serial.println("calibrando");
      }
  }
