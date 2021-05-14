#ifndef NETWORK_H
#define NETWORK_H

#include <WiFi.h>
#include "time.h"

const char* ssid = "your_ssid";
const char* pwd = "your_password";

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 0;
const int   daylightOffset_sec = 3600;

void connect_wifi();
char* get_time();

#endif
