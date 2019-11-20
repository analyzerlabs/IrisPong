void sensorInit(int m){
    distance = m;
  }
int readSensor(){
     int d = hcsr04.read(8, 9);
     delay(20);
     
     if(flag == false && d < 20 && d > 5){
        anterior = d;
        flag = true;
        pelotas ++;
        Serial.println(d);
     }
     else if(flag ==true && anterior > 20 && d < distance && d > 5){
        flag = false;
     }
     else if(flag ==true && (d > distance || d < 5)){
        anterior = d;   
     }
  }
