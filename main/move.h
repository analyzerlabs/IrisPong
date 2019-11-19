void StepMotor(int d,int v){
  digitalWrite(21,d);
  for(int i=0;i<200*v;i++){
      digitalWrite(20,HIGH);
      delay(1);
      digitalWrite(20,LOW);
      delay(1);
    }
}
