/*
 * MICROPROCESADORES
 * Seguidor solar
 * Equipo 2 
*/

//Librería paracontrolar los servomotores
#include <Servo.h>

/*Definimos los objetos tipo Servo*/
//Para el servo con movimiento horizontal
Servo servoH; //Objeto tipo Servo.
int servoh = 0;
int servohLimitHigh = 160;
int servohLimitLow = 20;

//Para el servo con movimiento vertical
Servo servoV; //Objeto tipo Servo.
int servov = 0; 
int servovLimitHigh = 160;
int servovLimitLow = 20;

//Creción e inicialización de variables  para los LDRs
int ldrtopl = 2; //LDR arriba a la izquierda.
int ldrtopr = 1; //LDR arriba a la derecha.
int ldrbotl = 3; //LDR abajo a la izquierda.
int ldrbotr = 0; //LDR abajo a la derecha

void setup () {
  servoH.attach(10);
  servoH.write(0);
  servoV.attach(9);
  servoV.write(0);
  delay(500); //Espera de 500ms.
}

void loop() {
  servoh = servoH.read();
  servov = servoV.read();
  //capturando valores analogicos de cada LDR
  int topl = analogRead(ldrtopl);
  int topr = analogRead(ldrtopr);
  int botl = analogRead(ldrbotl);
  int botr = analogRead(ldrbotr);
  // calculando el Promedio
  int avgtop = (topl + topr) / 2; //Promedio del top LDRs
  int avgbot = (botl + botr) / 2; //Promedio del bottom LDRs
  int avgleft = (topl + botl) / 2; //Promedio del left LDRs
  int avgright = (topr + botr) / 2; //Promedio del right LDRs

  if (avgtop < avgbot) {
    servoV.write(servov +1);
    if (servov > servovLimitHigh) { 
      servov = servovLimitHigh;
    }
    delay(10);
  }
  else if (avgbot < avgtop) {
    servoV.write(servov -1);
    if (servov < servovLimitLow) {
      servov = servovLimitLow;
    }
    delay(10);
  }
  else {
    servoV.write(servov);
  }
  
  if (avgleft > avgright) {
    servoH.write(servoh +1);
    if (servoh > servohLimitHigh) {
      servoh = servohLimitHigh;
    }
    delay(10);
  }
  else if (avgright > avgleft) {
    servoH.write(servoh -1);
    if (servoh < servohLimitLow) {
     servoh = servohLimitLow;
    }
    delay(10);
  }
  else {
    servoH.write(servoh);
  }
  delay(50);
}
