#include "network.h"

void connect_wifi() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(modem_ssid);
  WiFi.begin(modem_ssid, modem_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
