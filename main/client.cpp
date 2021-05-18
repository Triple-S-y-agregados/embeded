#include "client.h"
#include "control_servos.h"

TaskHandle_t Task1;
HTTPClient http;
StaticJsonDocument<200> doc;
String buffer = "";
String ServerIP = "http://192.168.0.3:44388/voltage";

// voltage
void postVoltage() {
  http.begin(ServerIP);
  http.addHeader("Content-Type", "application/json");
  String requestData = "";
  float V_pin = map(analogRead( PANEL_PIN ), 0, 4095, 0, 3); // Puede que sea necesario cambiar el voltaje máximo
  float V_panel = 4 * V_pin;
  doc["voltage"] = V_panel;
  doc["vertical"] = servoV.read();
  doc["horizontal"] = servoH.read();
  serializeJson( doc, buffer );

  Serial.println(buffer);
  
  int responseCode = http.POST( buffer );
  doc.clear();
  buffer="";
  Serial.println("Código de salida: ");
  Serial.println(responseCode);
}

void delete_client() {
  //vTaskDelete(Task1);
}
