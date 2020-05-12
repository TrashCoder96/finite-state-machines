#include <stdio.h>
#include <stdlib.h>
#include "finite_state_machine.c"
#include <stdbool.h>
#include <string.h>

int main() {
  char *str1 = "abayuiop";
  char *str2 = "yuiopret";
  printf("%d", sigma(str1, 8, str2, 8));
  return 0;
}