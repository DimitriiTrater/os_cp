#include <string.h>

uint32_t strlen(const_string str) {
  uint32_t len = 0;
  while (str[len]) {
    len++;
  }
  return len;
}
