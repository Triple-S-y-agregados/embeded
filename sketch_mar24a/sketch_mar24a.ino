/*
   MICROPROCESADORES
   Seguidor solar
   Equipo 2
*/

//Librería paracontrolar los servomotores

#include "control_servos.h" // Ya incluye ESP32Servo.h
Servo servoH;
Servo servoV;

void setup () {
  //Serial.begin( 115200 );
  initialize_servos( servoH, servoV );
}

void loop() {
  float V_pin = map(analogRead( PANEL_PIN ), 0, 4095, 0, 3); // Puede que sea necesario cambiar el voltaje máximo
  float V_panel = 4 * V_pin;
  update_servos( servoH, servoV );
  
}
