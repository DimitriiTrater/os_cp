#pragma once

#include <types.h>

#define CMOS_READ(addr)                                                        \
  ({                                                                           \
    outb_p(0x80 | addr, 0x70);                                                 \
    inb_p(0x71);                                                               \
  })
#define BCD_TO_BIN(val) ((val) = ((val)&15) + ((val) >> 4) * 10)
#define CLOCKS_PER_SEC 100

typedef long time_t;
typedef long clock_t;

static time_t startup_time = 0;

struct tm {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
};

clock_t clock(void);
time_t time(time_t *point_of_time);
double diff_time(time_t time_second, time_t time_first);

time_t make_time(struct tm *tm);

char *asc_time(const struct tm *point_of_time);
char *const_time(const time_t *point_of_time);
struct tm *gmtime(const time_t *point_of_time);
struct tm *local_time(const time_t *point_of_time);
size_t strftime(char *str, size_t smax, const char *fmt,
                const struct tm *point_of_time);
void time_zone_set(void);
