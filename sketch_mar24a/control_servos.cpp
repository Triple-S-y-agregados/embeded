
#include "control_servos.h"

float const ANALOG_BIAS = 0; // Puede que sea buena idea cambiar esto con el tiempo

void move_servo( Servo& servo, direction d ) {
  int servo_pos = servo.read();
  bool at_limit = (servo_pos == (d == RIGHT || d == UP) ? HIGH_LIMIT : LOW_LIMIT);
  int move_to = (at_limit) * HIGH_LIMIT + (!at_limit) * (servo_pos + d);
  servo.write( move_to );
}

void initialize_servos( Servo& servoH, Servo& servoV ) {
  servoH.attach(HORIZONTAL_SERVO_PIN);
  servoH.write(INITIAL_POSITION);
  servoV.attach(VERTICAL_SERVO_PIN);
  servoV.write(INITIAL_POSITION);
}

void update_servos( Servo& servoH, Servo& servoV ) {
  //capturando valores analogicos de cada LDR
  int topl = analogRead(TOP_LEFT_LDR);
  int topr = analogRead(TOP_RIGHT_LDR);
  int botl = analogRead(BOTTOM_LEFT_LDR);
  int botr = analogRead(BOTTOM_RIGHT_LDR);

  // calculando el Promedio
  int avgtop   = ( topl + topr ) / 2; //Promedio del top LDRs
  int avgbot   = ( botl + botr ) / 2; //Promedio del bottom LDRs
  int avgleft  = ( topl + botl ) / 2; //Promedio del left LDRs
  int avgright = ( topr + botr ) / 2; //Promedio del right LDRs

  if ( avgbot > avgtop + ANALOG_BIAS )          move_servo( servoV, UP    );
  else if ( avgbot  + ANALOG_BIAS < avgtop)     move_servo( servoV, DOWN  );
  delay(50);

  if ( avgleft > avgright  + ANALOG_BIAS )      move_servo( servoH, RIGHT );
  else if ( avgleft + ANALOG_BIAS < avgright )  move_servo( servoH, LEFT  );
  delay(50);
}
