#include "client.h"

TaskHandle_t Task1;

void initialize_client() {
  //xTaskCreatePinnedToCore(create_server, "Server", 10000, NULL, 0, &Task1, 1);
}


void delete_client() {
  //vTaskDelete(Task1);
}
