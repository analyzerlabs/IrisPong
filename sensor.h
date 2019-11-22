//Creamos la funcion sensorInitpara incializar al sensor HCSR04
void sensorInit(int m){
    distance = m;
  }

//Creamos la funcion readSensor para medir las distancias
int readSensor(){
     int d = hcsr04.read(8, 9);   // leemos el sensor conectado a los pines 8 y 9
     delay(20);                   //esperamos 20 ms para una correcta lectura
     
     if(flag == false && d < 20 && d > 5){   // si la medida es menor a 20 y mayor a 5 entonces se dice que paso 1 pelota
        anterior = d;
        flag = true;
        pelotas ++;
        Serial.println(d);     // imprimimos la distancia para corroborar
     }
     else if(flag ==true && anterior > 20 && d < distance && d > 5){  //si la medida es mayor a 20 o menor a 5 , se dice que nada ah pasado 
        flag = false;
     }
     else if(flag ==true && (d > distance || d < 5)){ //si la medida es menor a 20 y mayor a 5 pero la anterior media tambien cumple
        anterior = d;                                   // con lo mismo entonces no se produjo cambio
     }
  }
