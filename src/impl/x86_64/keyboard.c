#include <char.h>
#include <io.h>
#include <keyboard.h>
#include <print.h>
#include <types.h>

char get_input_keycode() {
  char ch = 0;
  while ((ch = inb(KEYBOARD_PORT)) != 0) {
    if (ch > 0) {
      return ch;
    }
  }
  return ch;
}

void wait_for_io(uint32_t timer_count) {
  while (1) {
    asm volatile("nop");
    timer_count--;
    if (timer_count <= 0)
      break;
  }
}

void sleep(uint32_t timer_count) { wait_for_io(timer_count); }

void test_input() {
  char ch = 0;
  char keycode = 0;
  do {
    keycode = get_input_keycode();
    if (keycode == KEY_ENTER) {
      print_newline();
    } else {
      ch = get_ascii_char(keycode);
      print_char(ch);
    }
    sleep(0x02FFFFFF);
  } while (1);
}
