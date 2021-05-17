#include "server.h"

TaskHandle_t Task1;
StaticJsonDocument<1000> jsonDocument;
char json_buffer[1000];
WebServer server(5000);

void initialize_server() {
  server_routing( server );
  server.begin();
  xTaskCreatePinnedToCore(create_server, "Server", 10000, NULL, 0, &Task1, 1);
}

void create_server(void* this_parameter_is_completely_irrelevant_so_dont_use_it) {
  server.handleClient();
}

void delete_server() {
  vTaskDelete(Task1);
}

void server_routing( WebServer& server) {
  server.on("/query_last", HTTP_GET,  query_last_n);
}

void query_last_n() {
  Serial.println( "Querying Intensity..." );
  if (server.args() != 1){
    server.send(400, "text/plain", "BadRequest" + "\r\n");
    return; 
  }
  
  String str_id = server.arg(0); // parse id                              <-- TODO
  
  jsonDocument.clear();
  // Query y send to jsonDocument using add_json_object.                  <-- TODO
  serializeJson( jsonDocument, json_buffer );
  server.send(200, "application/json", json_buffer);
}

// Basado en el código de https://www.survivingwithandroid.com/esp32-rest-api-esp32-api-server/
void add_json_object(char *timestamp, float value) {
  JsonObject obj = jsonDocument.createNestedObject();
  jsonDocument["Time"] = timestamp;
  jsonDocument["Intensity"] = value;
}
