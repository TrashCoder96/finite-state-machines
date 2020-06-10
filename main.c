#include <stdio.h>
#include <stdlib.h>
#include "finite_state_machine.c"
#include <stdbool.h>
#include <string.h>

int main() {
  struct FiniteStateMachine *m = compile_finite_state_machine("ababc", 5);
  char *str = "sdfgdababcucd";
  char c = str[0];
  int i = 0;
  bool runned = true;
  while (c != '\0' && runned) {
    runned = run(m, c, 5) == 0;
    i++;
    c = str[i];
  }
  printf(runned ? "substring is not found\n" : "substring is found\n");
  return 0;
}
