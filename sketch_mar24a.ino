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

void move_right() {
  int servo_horizontal_position = servoH.read();

  int position_at_limit = servo_horizontal_position == HORIZONTAL_HIGH_LIMIT;
  int lower_than_limit = !position_at_limit;

  int next_position = (position_at_limit) * HORIZONATAL_HIGH_LIMIT + (lower_than_limit) * (servo_horizontal_position + 1);

  servoH.write(next_position);
}

void move_left() {
  int servo_horizontal_position = servoH.read();

  int position_at_limit = servo_horizontal_position == HORIZONTAL_LOW_LIMIT;
  int higher_than_limit = !position_at_limit;

  int next_position = (position_at_limit) * HORIZONATAL_LOW_LIMIT + (higher_than_limit) * (servo_horizontal_position - 1);

  servoH.write(next_position);
}

void move_up() {
  int servo_vertical_position = servoV.read();

  int position_at_limit = servo_vertical_position == horizontal_high_limit;
  int lower_than_limit = !position_at_limit;

  int next_position = (position_at_limit) * horizonatal_high_limit + (lower_than_limit) * (servo_vertical_position + 1);

  servoV.write(next_position);
}

void move_down() {
  int servo_vertical_position = servoV.read();

  int position_at_limit = servo_horizontal_position == HORIZONTAL_LOW_LIMIT;
  int higher_than_limit = !position_at_limit;

  int next_position = (position_at_limit) * HORIZONATAL_LOW_LIMIT + (higher_than_limit) * (servo_vertical_position - 1);

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
