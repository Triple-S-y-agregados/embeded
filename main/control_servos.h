
#ifndef CONTROL_SERVOS_H
#define CONTROL_SERVOS_H


#include <ESP32Servo.h>

#define INITIAL_POSITION 0
#define PANEL_PIN 39

// Servos
#define HORIZONTAL_SERVO_PIN 19
#define VERTICAL_SERVO_PIN 18

// LDRs
#define TOP_RIGHT_LDR 34
#define TOP_LEFT_LDR 35
#define BOTTOM_RIGHT_LDR 32
#define BOTTOM_LEFT_LDR 33

// Estoy suponiendo estos
#define HIGH_LIMIT 180
#define LOW_LIMIT    0

//Para el servo con movimiento horizontal
extern Servo servoH; //Objeto tipo Servo.
//Para el servo con movimiento vertical
extern Servo servoV; //Objeto tipo Servo.

enum direction { LEFT = -1, RIGHT = 1, DOWN = -1, UP = 1 };

void move_servo( Servo&, direction );
void initialize_servos( Servo&, Servo& );
void update_servos(Servo&, Servo&);

#endif
