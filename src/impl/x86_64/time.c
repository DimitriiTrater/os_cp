#include <time.h>

#define MINUTE 60
#define HOUR (60 * MINUTE)
#define DAY (24 * HOUR)
#define YEAR (365 * DAY)

static int month[12] = {
    0,
    DAY * (31),
    DAY * (31 + 29),
    DAY * (31 + 29 + 31),
    DAY * (31 + 29 + 31 + 30),
    DAY * (31 + 29 + 31 + 30 + 31),
    DAY * (31 + 29 + 31 + 30 + 31 + 30),
    DAY * (31 + 29 + 31 + 30 + 31 + 30 + 31),
    DAY * (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31),
    DAY * (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30),
    DAY * (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31),
    DAY * (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30)};

time_t make_time(struct tm *tm) {

  time_t result;
  int year;

  year = tm->tm_year - 70;

  result = YEAR * year + DAY * ((year + 1) / 4);
  result += month[tm->tm_mon];

  if (tm->tm_mon > 1 && ((year + 2) % 4))
    result -= DAY;

  result += DAY * (tm->tm_mday - 1);
  result += HOUR * tm->tm_hour;
  result += MINUTE * tm->tm_min;
  result += tm->tm_sec;

  return result;
}
