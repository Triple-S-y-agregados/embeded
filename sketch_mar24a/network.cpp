#include "network.h";

void connect_wifi() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected");
}