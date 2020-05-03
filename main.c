#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.c"

int main() {
  struct LinkedList *list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
  list->head = NULL;
  int i1 = 1;
  int i2 = 2;
  pushItem(list, &i1);
  pushItem(list, &i2);
  removeItem(list, &i2);
  removeItem(list, &i1);
  free(list);
  return 0;
}