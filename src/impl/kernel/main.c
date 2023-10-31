#include "print.h"
#include "keyboard.h"

void kernel_main() {
  print_clear();
  print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_WHITE);
  println_str("Welcome to our 64-bit kernel!");
  test_input();
}
