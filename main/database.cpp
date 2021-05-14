#include "database.h"

void initialize_database() {
  Serial.print(F("InitSD..\n"));
  if (!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED)) {
    Serial.println(F("Failed to mount file Serial"));
    return;
  }
  SPI.begin();
  SD_MMC.begin();
  SD.begin();

  Serial.print(F("done.\n"));
}

void log_data(int analog_pin) {
  myFile = fopen(database_name, "w+b");

  if (myFile) {
    struct dblog_write_context ctx;

    ctx.buf = buf;
    ctx.col_count = 10; //Num of columns for each row
    ctx.page_resv_bytes = 0;
    ctx.page_size_exp = 12;
    ctx.max_pages_exp = 0;
    ctx.read_fn = read_fn_wctx;
    ctx.flush_fn = flush_fn;
    ctx.write_fn = write_fn;

    int res = dblog_write_init(&ctx);

    if (!res) {
      int val = analogRead(analog_pin);
      res = dblog_set_col_val(&ctx, 0, DBLOG_TYPE_INT, &val, sizeof(int));
    }
    Serial.print(F("\nLogging completed. Finalizing...\n"));

    if (!res)
      res = dblog_finalize(&ctx);

    fclose(myFile);

    if (res)
      print_error(res);
  } else {
    Serial.print(F("Open Error\n"));
  }
}

void get_record() {}

int32_t read_fn_wctx(struct dblog_write_context *ctx, void *buf, uint32_t pos, size_t len) {
  if (fseek(myFile, pos, SEEK_SET))
    return DBLOG_RES_SEEK_ERR;
  size_t ret = fread(buf, 1, len, myFile);
  if (ret != len)
    return DBLOG_RES_READ_ERR;
  return ret;
}

int flush_fn(struct dblog_write_context *ctx) {
  return DBLOG_RES_OK;
}

int32_t write_fn(struct dblog_write_context *ctx, void *buf, uint32_t pos, size_t len) {
  if (fseek(myFile, pos, SEEK_SET))
    return DBLOG_RES_SEEK_ERR;
  size_t ret = fwrite(buf, 1, len, myFile);
  if (ret != len)
    return DBLOG_RES_ERR;
  if (fflush(myFile))
    return DBLOG_RES_FLUSH_ERR;
  fsync(fileno(myFile));
  return ret;
}

void print_error(int res) {
  Serial.print(F("Err:"));
  Serial.print(res);
  Serial.print(F("\n"));
}