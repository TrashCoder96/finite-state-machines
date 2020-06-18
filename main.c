#include <stdio.h>
#include <stdlib.h>
#include "finite_state_machine.c"
#include <stdbool.h>
#include <string.h>

int main() {
  struct FiniteStateMachine *m = compile_finite_state_machine("bc", 2);
  char *str = "abcde";
  char c = str[0];
  int i = 0;
  bool runned = true;
  while (c != '\0' && runned) {
    runned = run(m, c, 2) == 0;
    i++;
    c = str[i];
  }
  destroy_finite_state_machine(m);
  printf(runned ? "substring is not found\n" : "substring is found\n");
  return 0;
}
