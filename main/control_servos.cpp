
#include "control_servos.h"

float const ANALOG_BIAS = 3; // Puede que sea buena idea cambiar esto con el tiempo

int average(int a, int b) {
  return (a + b) / 2;
}

void move_servo( Servo& servo, direction d ) {
  int servo_pos = servo.read();
  int limit = (d == RIGHT || d == UP) ? HIGH_LIMIT : LOW_LIMIT;
  bool at_limit = servo_pos == limit;
  int move_to = (at_limit) * limit + (!at_limit) * (servo_pos + d);
  servo.write(move_to);

  Serial.print("Move to: ");
  Serial.print(move_to);
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
  int avgtop   = average(topl, topr); //Promedio del top LDRs
  int avgbot   = average(botl, botr); //Promedio del bottom LDRs
  int avgleft  = average(topl, botl); //Promedio del left LDRs
  int avgright = average(topr, botr); //Promedio del right LDRs

  Serial.println("\nVertical servo: ");
  
  if ( avgbot > avgtop + ANALOG_BIAS )          move_servo( servoV, DOWN  );
  else if ( avgbot  + ANALOG_BIAS < avgtop)     move_servo( servoV, UP    );
  delay(10);

  Serial.println("\nHorizontal Servo: ");

  if ( avgleft > avgright  + ANALOG_BIAS )      move_servo( servoH, LEFT  );
  else if ( avgleft + ANALOG_BIAS < avgright )  move_servo( servoH, RIGHT );
  delay(10);
}
