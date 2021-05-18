
#include "control_servos.h"

float const ANALOG_BIAS = 120; // Puede que sea buena idea cambiar esto con el tiempo

int average(int a, int b) {
  return (a + b) / 2;
}

void move_servo( Servo& servo, direction d ) {
  int servo_pos = servo.read();
  int limit = (d == RIGHT || d == UP) ? HIGH_LIMIT : LOW_LIMIT;
  bool at_limit = servo_pos == limit;
  int move_to = (at_limit) * limit + (!at_limit) * (servo_pos + d);
  servo.write(move_to);
}

void initialize_servos( Servo& servoH, Servo& servoV ) {
  servoH.attach(HORIZONTAL_SERVO_PIN);
  servoH.write(INITIAL_POSITION);
  servoV.attach(VERTICAL_SERVO_PIN);
  servoV.write(INITIAL_POSITION);
}

void update_servos( Servo& servoH, Servo& servoV ) {
  bool readyV = false;
  bool readyH = false;

  int topl = 0, topr = 0, botl = 0, botr = 0;


  //capturando valores analogicos de cada LDR
  topl = analogRead(TOP_LEFT_LDR);
  topr = analogRead(TOP_RIGHT_LDR);
  botl = analogRead(BOTTOM_LEFT_LDR);
  botr = analogRead(BOTTOM_RIGHT_LDR);

  while (!readyV) {
    if ( average(botl, botr) > average(topl, topr) + ANALOG_BIAS )        move_servo( servoV, DOWN  );
    else if ( average(botl, botr)  + ANALOG_BIAS < average(topl, topr))   move_servo( servoV, UP    );
    else readyV = true;
    delay(10);
  }

  while (!readyH) {
    if ( average(topl, botl) > average(topr, botr)  + ANALOG_BIAS )       move_servo( servoH, LEFT  );
    else if ( average(topl, botl) + ANALOG_BIAS < average(topr, botr) )   move_servo( servoH, RIGHT );
    else readyH = true;
    delay(10);
  }
}
