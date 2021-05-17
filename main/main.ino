/*
   MICROPROCESADORES
   Seguidor solar
   Equipo 2
*/

#include "control_servos.h" // Ya incluye ESP32Servo.h
#include "network.h"
#include "client.h"
Servo servoH;
Servo servoV;

void setup () {
  Serial.begin( 115200 );
  initialize_servos( servoH, servoV );
  connect_wifi();
}

void loop() {
  update_servos( servoH, servoV );
  postVoltage();
  delay(1000);
}
