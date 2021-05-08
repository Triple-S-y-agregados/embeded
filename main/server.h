#ifndef SERVER_H
#define SERVER_H

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void initialize_server();
void create_server(void*);
void delete_server();

#endif
