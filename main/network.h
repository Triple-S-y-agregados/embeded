#ifndef NETWORK_H
#define NETWORK_H

#include <WiFi.h>
#include "time.h"

extern const char* ssid;
extern const char* pwd;

extern const char* ntpServer;
extern const long  gmtOffset_sec;
extern const int   daylightOffset_sec;

void connect_wifi();
char* get_time();

#endif
