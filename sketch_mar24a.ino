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

void move_right() {
  int servo_horizontal_position = servoH.read();
  int next_position = servo_horizontal_position + 1;

  if (next_position > SERVO_HIGH_LIMIT)
    next_position = SERVO_HIGH_LIMIT;

  servoH.write(next_position);
}

void move_left() {
  int servo_horizontal_position = servoH.read();
  int next_position = servo_horizontal_position - 1;

  if (next_position < SERVO_LOW_LIMIT)
    next_position = SERVO_LOW_LIMIT;
  
  servoH.write(next_position);
}

void move_up() {
  int servo_vertical_position = servoV.read();
  int next_position = servo_vertical_position + 1;

  if (next_position > SERVO_HIGH_LIMIT)
    next_position = SERVO_HIGH_LIMIT;

  servoV.write(next_position);
}

void move_down() {
  int servo_vertical_position = servoV.read();
  int next_position = servo_vertical_position - 1;
  
  if (next_position < SERVO_LOW_LIMIT)
    next_position = SERVO_LOW_LIMIT;

  servoV.write(next_position);
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
    move_up();
  }
  else if (avgbot < avgtop) {
    move_down();
  }
  delay(50);
  
  if (avgleft > avgright) {
    move_right();
  }
  else if (avgright > avgleft) {
    move_left();
  }
  delay(50);
}
