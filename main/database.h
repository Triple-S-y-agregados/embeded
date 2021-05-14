#ifndef DATABASE_H
#define DATABASE_H

#include "ulog_sqlite.h"
#include <SPI.h>
#include <FS.h>
#include "SPIFFS.h"
#include "SD_MMC.h"
#include <SD.h>
#include <sd_diskio.h>
#include <sd_defines.h>

#define FORMAT_SPIFFS_IF_FAILED true
#define MAX_STR_LEN 500

#define BUF_SIZE 4096
byte buf[BUF_SIZE];
const char* database_name = "solar_db";
extern const char sqlite_sig[];

FILE *myFile;

void initialize_database();
void log_data();
void get_record();

int32_t read_fn_wctx(struct dblog_write_context*, void*, uint32_t, size_t);
int flush_fn(struct dblog_write_context*);
int32_t write_fn(struct dblog_write_context*, void*, uint32_t, size_t);
void print_error(int);

#endif
