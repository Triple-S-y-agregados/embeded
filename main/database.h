#ifndef DATABASE_H
#define DATABASE_H

#include "ulog_sqlite.h"
#include <SPI.h>
#include <FS.h>
#include "SPIFFS.h"
#include "SD_MMC.h"
#include "SD.h"

#define FORMAT_SPIFFS_IF_FAILED true
#define MAX_FILE_NAME_LEN 100
#define MAX_STR_LEN 500

#define BUF_SIZE 4096

#endif
