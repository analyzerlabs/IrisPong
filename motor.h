void motorInit(){
      pinMode(dirPin,OUTPUT);
      pinMode(stepPin,OUTPUT);
      digitalWrite(stepPin,LOW);
  }
void irisInit(){
      iris.attach(7); 
}

void irisOpen(int angle){
      iris.write(angle);
      delay(1);
  }
// funcion para hacer funcionar al motor a paso en su
// forma mas basica , speed representa el numero de pasos por segundo

void stepMotor(int speed){
    int t = 2500/speed;
    if(t<500) t = 500;
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(t);
  }
  
void moveMotor(int dir,int vueltas , int speed){
  int d = 0 ,v = 0;
  digitalWrite(dirPin,dir);
  for(int i=0;i<200*v;i++){
      stepMotor(speed);
    }
}
