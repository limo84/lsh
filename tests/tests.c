#define LSH

#include "../lsh_string.h"
#include "../lsh_logger.h"
#include "../lsh_regex.h"

int main() {
  String *s;
  string_init(s, "Hello World");
  string_print(s);
  logger_open_logfile("./logfile.log");
  logger_log("Hallo Welt %d\n", 42);
  logger_log("Zweite Zeile %d\n", 111);
  return 0;
}
