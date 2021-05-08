#include "server.h"

TaskHandle_t Task1;

void initialize_server() {
    xTaskCreatePinnedToCore(create_server, "Server", 10000, NULL, 0, &Task1, 1);
}

void create_server(void* this_parameter_is_completely_irrelevant_so_dont_use_it) {}

void delete_server() {
    vTaskDelete(Task1);
}
