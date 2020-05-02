#include <stdio.h>
#include <stdlib.h>

int main() {
  struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList*));
  free(list);
  return 0;
}