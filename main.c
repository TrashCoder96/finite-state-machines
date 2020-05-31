#include <stdio.h>
#include <stdlib.h>
#include "finite_state_machine.c"
#include <stdbool.h>
#include <string.h>

int main() {
  struct FiniteStateMachine *m = compile_finite_state_machine("ababc", 5);
  return 0;
}