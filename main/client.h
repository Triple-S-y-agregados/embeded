#ifndef SERVER_H
#define SERVER_H

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include <ArduinoJson.h>
#include <HTTPClient.h>

#define PANEL_PIN 39

// Port: 44388
void initialize_client();
void delete_client();
void postVoltage();

#endif
