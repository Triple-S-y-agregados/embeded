/*
 * MICROPROCESADORES
 * Seguidor solar
 * Equipo 2 
*/

//Librería paracontrolar los servomotores
#include <ESP32Servo.h>

/*Definimos los objetos tipo Servo*/
//Para el servo con movimiento horizontal
Servo servoH; //Objeto tipo Servo.
//Para el servo con movimiento vertical
Servo servoV; //Objeto tipo Servo.

#define HORIZONTAL_SERVO_PIN 10
#define VERTICAL_SERVO_PIN 6

#define SERVO_HIGH_LIMIT 160
#define SERVO_LOW_LIMIT 20

#define INITIAL_POSITION 0

#define TOP_RIGHT_LDR 1
#define TOP_LEFT_LDR 2
#define BOTTOM_RIGHT_LDR 0
#define BOTTOM_LEFT_LDR 3

#define HIGH_LIMIT 180
#define LOW_LIMIT    0

enum direction{ LEFT=-1, RIGHT=1, DOWN=-1, UP=1 };

void move_servo( Servo& servo, direction d ){
  int servo_pos = servo.read();
  bool at_limit = (servo_pos == (d == RIGHT || d == UP)? HIGH_LIMIT : LOW_LIMIT);
  int move_to = (at_limit) * HIGH_LIMIT + (!at_limit) * (servo_pos + 1);
  servo.write( move_to );
}

void setup () {
  servoH.attach(HORIZONTAL_SERVO_PIN);
  servoH.write(INITIAL_POSITION);
  servoV.attach(VERTICAL_SERVO_PIN);
  servoV.write(INITIAL_POSITION);
}

void loop() {
  //capturando valores analogicos de cada LDR
  int topl = analogRead(TOP_LEFT_LDR);
  int topr = analogRead(TOP_RIGHT_LDR);
  int botl = analogRead(BOTTOM_LEFT_LDR);
  int botr = analogRead(BOTTOM_RIGHT_LDR);
  // calculando el Promedio
  int avgtop = (topl + topr) / 2; //Promedio del top LDRs
  int avgbot = (botl + botr) / 2; //Promedio del bottom LDRs
  int avgleft = (topl + botl) / 2; //Promedio del left LDRs
  int avgright = (topr + botr) / 2; //Promedio del right LDRs

  if (avgtop < avgbot) {
    move_servo(servoV, UP);
  }
  else if (avgbot < avgtop) {
    move_servo(servoV, DOWN);
  }
  delay(50);
  
  if (avgleft > avgright) {
    move_servo(servoH, RIGHT);
  }
  else if (avgright > avgleft) {
    move_servo(servoH, RIGHT);
  }
  delay(50);
}
