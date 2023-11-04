#include "time.h"
#include <io.h>
#include <keyboard.h>
#include <print.h>

extern time_t make_time(struct tm *tm);

static void time_init(void) {
  struct tm time;

  do {
    time.tm_sec = CMOS_READ(0);
    print_int(time.tm_sec);
    print_char(':');
    time.tm_min = CMOS_READ(2);
    print_int(time.tm_min);
    print_char(':');
    time.tm_hour = CMOS_READ(4);
    print_int(time.tm_hour);
    print_char(':');
    time.tm_mday = CMOS_READ(7);
    print_int(time.tm_mday);
    print_char(':');
    time.tm_mon = CMOS_READ(8);
    print_int(time.tm_mon);
    print_char(':');
    time.tm_year = CMOS_READ(9);
    print_int(time.tm_year);
    print_char(':');
    print_char('\n');
  } while (time.tm_sec != CMOS_READ(0));
  BCD_TO_BIN(time.tm_sec);
  BCD_TO_BIN(time.tm_min);
  BCD_TO_BIN(time.tm_hour);
  BCD_TO_BIN(time.tm_mday);
  BCD_TO_BIN(time.tm_mon);
  BCD_TO_BIN(time.tm_year);

  print_int(time.tm_sec);
  print_char(':');
  print_int(time.tm_min);
  print_char(':');
  print_int(time.tm_hour);
  print_char(':');
  print_int(time.tm_mday);
  print_char(':');
  print_int(time.tm_mon);
  print_char(':');
  print_int(time.tm_year);
  print_char(':');
  print_char('\n');

  startup_time = make_time(&time);
}

void kernel_main(void) {
  print_clear();
  time_init();
  print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_WHITE);
  println_str("Welcome to our 64-bit kernel!");
  // print_int(startup_time);
  test_input();
}
