int luzRoja = 2;
int luzAmarilla = 3;
int luzVerde = 4;
int luzAzul = 5;
int luzBlanca = 6;
int botonRojo = 12;
int botonAmarillo = 11;
int botonVerde = 10;
int botonAzul = 9;
int botonBlanco = 8;
int contador = 0;
int miArray[16];
int intentos = 0;
boolean fin = false;

void setup()
{
  pinMode(luzRoja, OUTPUT);
  pinMode(luzAmarilla, OUTPUT);
  pinMode(luzVerde, OUTPUT);
  pinMode(luzAzul, OUTPUT);
  pinMode(luzBlanca, OUTPUT);
  pinMode(botonRojo, INPUT);
  pinMode(botonAmarillo, INPUT);
  pinMode(botonVerde, INPUT);
  pinMode(botonAzul, INPUT);
  pinMode(botonBlanco, INPUT);
}

void loop() {
  contador = 0;
  intentos = 0;
  fin = false;
  while(digitalRead(botonBlanco) == LOW && !fin){
    iniciarJuego();
    generarSecuencia();
    for (int i = 0; i < intentos; i++){
       delay(700);
       for (int j = 0; j <= contador; j++){
         digitalWrite(miArray[j],HIGH);
         delay(300);
         digitalWrite(miArray[j],LOW);
         delay(300);
       }
       for (int k = 0; k <= contador; k++){
         if (encenderLuz() == miArray[k]){
          digitalWrite(miArray[k],HIGH);
          delay(200);
          digitalWrite(miArray[k],LOW);
          delay(200);
          } else {
            finalizarJuego();
            fin = true;
            break;
              }
        }
      if (fin){
        break;
      } else {
        contador++;
      }
    }
    if (!fin){
      ganarJuego();
    }
  }
}

int encenderLuz(){
  int opcion = 0;
  while (opcion == 0){
    if (digitalRead(botonRojo) == LOW) {
      opcion = mantenerLuz(botonRojo, luzRoja);
    }
    if (digitalRead(botonAmarillo) == LOW) {
      opcion = mantenerLuz(botonAmarillo, luzAmarilla);
    }
    if (digitalRead(botonVerde) == LOW) {
      opcion = mantenerLuz(botonVerde, luzVerde);
    }
    if (digitalRead(botonAzul) == LOW) {
      opcion = mantenerLuz(botonAzul, luzAzul);
    }
  }
  return opcion;
}

int mantenerLuz(int boton, int luz){
  while(digitalRead(boton) == LOW){
    digitalWrite(luz,HIGH);
  }
  while(digitalRead(boton) == LOW){
    digitalWrite(luz,LOW);
  }
  return luz;
}
 
 void iniciarJuego() {
   for (int i = 2; i <= 6; i++){
     digitalWrite(i,HIGH);
   }
   delay(2000);
   for (int i = 2; i <= 6; i++){
     digitalWrite(i,LOW);
   }  
   delay(1000);
}
void generarSecuencia(){
  while (intentos == 0){
    if(digitalRead(botonRojo) == HIGH && digitalRead(botonAmarillo) == HIGH && digitalRead(botonVerde) == HIGH && digitalRead(botonAzul) == HIGH){
      for (int i = 2; i <= 5; i++){
       digitalWrite(i,HIGH);
      }
      for (int i = 2; i <= 5; i++){
       digitalWrite(i,LOW);
      }
    }
   
    if (digitalRead(botonRojo) == LOW) {
      intentos = 4;
      for (int i = 2; i <= 5; i++){
       digitalWrite(i,LOW);
      }
    }
    if (digitalRead(botonAmarillo) == LOW) {
      intentos = 8;
      for (int i = 2; i <= 5; i++){
       digitalWrite(i,LOW);
      }
    }
    if (digitalRead(botonVerde) == LOW) {
      intentos = 12;
      for (int i = 2; i <= 5; i++){
       digitalWrite(i,LOW);
      }
    }
    if (digitalRead(botonAzul) == LOW) {
      intentos = 16;
      for (int i = 2; i <= 5; i++){
       digitalWrite(i,LOW);
      }
    }
  }
  for(int i = 0; i < intentos; i++){
    miArray[i] = random(2,6);
  }
}
void finalizarJuego() {
  for (int i = 2; i <= 6; i++){
     digitalWrite(i,HIGH);
   }
   delay(3000);
   for (int i = 2; i <= 6; i++){
     digitalWrite(i,LOW);
   }  
   delay(500);
}

void ganarJuego() {
  int vueltas = 0;
  while(vueltas < 6){
    for (int i = 2; i <= 6; i++){
     digitalWrite(i,HIGH);
   }
   delay(100);
   for (int i = 2; i <= 6; i++){
     digitalWrite(i,LOW);
   }
   delay(100);
    vueltas+= 1;
  }
}
