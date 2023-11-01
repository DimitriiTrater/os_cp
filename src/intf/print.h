#pragma once

#include "types.h"

enum {
  PRINT_COLOR_BLACK = 0,
  PRINT_COLOR_BLUE = 1,
  PRINT_COLOR_GREEN = 2,
  PRINT_COLOR_CYAN = 3,
  PRINT_COLOR_RED = 4,
  PRINT_COLOR_MAGENTA = 5,
  PRINT_COLOR_BROWN = 6,
  PRINT_COLOR_LIGHT_GRAY = 7,
  PRINT_COLOR_DARK_GRAY = 8,
  PRINT_COLOR_LIGHT_BLUE = 9,
  PRINT_COLOR_LIGHT_GREEN = 10,
  PRINT_COLOR_LIGHT_CYAN = 11,
  PRINT_COLOR_LIGHT_RED = 12,
  PRINT_COLOR_PINK = 13,
  PRINT_COLOR_YELLOW = 14,
  PRINT_COLOR_WHITE = 15,
};

uint32_t digit_count(int32_t num);
void from_int_to_alpha(int32_t num, char *number);

void print_clear();
void print_newline();

void print_char(char ch);
void println_char(char ch);

void print_str(const char *str);
void println_str(const char *str);

void print_int(int32_t num);

void print_set_color(uint8_t foreground, uint8_t background);
void print_information_about_system();
