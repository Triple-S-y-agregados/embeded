#ifndef SERVER_H
#define SERVER_H

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include <ArduinoJson.h>

// Port: 5000
// Las
void initialize_client();
void delete_client();

#endif
