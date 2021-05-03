/*
   MICROPROCESADORES
   Seguidor solar
   Equipo 2
*/

#include "control_servos.h" // Ya incluye ESP32Servo.h
Servo servoH;
Servo servoV;

#include "network.h"

#include "server.h"

void setup () {
  Serial.begin( 115200 );
  initialize_servos( servoH, servoV );
  connect_wifi();
  //initialize_server();
}

void loop() {
  float V_pin = map(analogRead( PANEL_PIN ), 0, 4095, 0, 3); // Puede que sea necesario cambiar el voltaje máximo
  float V_panel = 4 * V_pin;
  update_servos( servoH, servoV );
}
