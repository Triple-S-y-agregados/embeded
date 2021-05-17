#include "client.h"

TaskHandle_t Task1;
HTTPClient http;
StaticJsonDocument<200> doc;
String buffer = "";
String ServerIP = "http://192.168.0.3:44388/";


void initialize_client() {
  // xTaskCreatePinnedToCore(create_server, "Server", 10000, NULL, 0, &Task1, 1);
}

// voltage
void postVoltage() {
  http.begin(ServerIP + "voltage");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  String requestData = "";
  float V_pin = map(analogRead( PANEL_PIN ), 0, 4095, 0, 3); // Puede que sea necesario cambiar el voltaje máximo
  float V_panel = 4 * V_pin;
  doc["voltage"] = V_panel;
  serializeJson( doc, buffer );
  int responseCode = http.POST( buffer );
  Serial.println("Código de salida: " + responseCode);
}

void delete_client() {
  //vTaskDelete(Task1);
}
