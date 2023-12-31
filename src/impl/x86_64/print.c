#include <print.h>
#include <types.h>

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct Char {
  uint8_t character;
  uint8_t color;
};

struct Char *buffer = (struct Char *)0xb8000;

size_t col = 0;
size_t row = 0;

uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;

void clear_row(size_t row) {
  struct Char empty = (struct Char){
      .character = ' ',
      .color = color,
  };

  for (size_t col = 0; col < NUM_COLS; col++) {
    buffer[col + NUM_COLS * row] = empty;
  }
}

uint32_t digit_count(int32_t num) {
  uint32_t count = 0;
  if (num == 0) {
    return 1;
  }
  while (num > 0) {
    count++;
    num /= 10;
  }
  return count;
}

void from_int_to_alpha(int32_t num, char *number) {
  uint32_t dc = digit_count(num);
  size_t index = dc - 1;
  char x;
  if (num == 0 && dc == 1) {
    number[0] = '0';
    number[1] = '\0';
  } else {
    while (num != 0) {
      x = num % 10;
      number[index] = x + '0';
      index--;
      num /= 10;
    }
    number[dc] = '\0';
  }
}

void print_clear() {
  for (size_t i = 0; i < NUM_ROWS; i++) {
    clear_row(i);
  }
}

void print_newline() {
  col = 0;
  if (row < NUM_ROWS - 1) {
    row++;
    return;
  }

  for (size_t row = 1; row < NUM_ROWS; row++) {
    for (size_t col = 0; col < NUM_COLS; col++) {
      struct Char ch = buffer[col + NUM_COLS * row];
      buffer[col + NUM_COLS * (row - 1)] = ch;
    }
  }
  clear_row(NUM_COLS - 1);
}

void print_char(char ch) {
  if (ch == '\n') {
    print_newline();
    return;
  }

  if (col > NUM_COLS) {
    print_newline();
  }

  buffer[col + NUM_COLS * row] = (struct Char){
      .character = (uint8_t)ch,
      .color = color,
  };

  col++;
}

void println_char(char ch) {
  print_char(ch);
  print_newline();
}

void print_str(const char *str) {
  for (size_t i = 0; 1; i++) {
    char ch = (uint8_t)str[i];

    if (ch == '\0') {
      return;
    }

    print_char(ch);
  }
}

void println_str(const char *str) {
  print_str(str);
  print_newline();
}

void print_int(int32_t num) {
  char *t = " ";
  from_int_to_alpha(num, t);
  print_str(t);
}

void print_set_color(uint8_t foreground, uint8_t background) {
  color = foreground + (background < 4);
}

void print_information_about_system() {
  const char *about_os = "Free and Open OS.\n Version 0.0.1 \n";
  print_str(about_os);
}
