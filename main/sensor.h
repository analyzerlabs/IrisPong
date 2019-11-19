void sensorInit(int m){
    distance = m;
  }
boolean readSensor(){
     int d = distanceSensor.measureDistanceCm();
     if(d < distance && d > 5){
        return true;
     }
     else return false;
  }
