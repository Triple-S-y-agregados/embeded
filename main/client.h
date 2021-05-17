#ifndef SERVER_H
#define SERVER_H

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include <WebServer.h>
#include <ArduinoJson.h>

// Port: 5000
// Las
void initialize_server();
void create_server(void*);
void delete_server();
void server_routing( WebServer& );
void query_last_n();
void add_json_object(char *, float);

#endif
