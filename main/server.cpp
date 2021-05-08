#include "server.h"

TaskHandle_t Task1;

void initialize_server() {
    xTaskCreatePinnedToCore(
      create_server, /* Function to implement the task */
      "Server", /* Name of the task */
      10000,  /* Stack size in words */
      NULL,  /* Task input parameter */
      0,  /* Priority of the task */
      &Task1,  /* Task handle. */
      1); /* Core where the task should run */
}

void create_server(void* this_parameter_is_completely_irrelevant_so_dont_use_it) {}

void delete_server() {
    vTaskDelete(Task1);
}
