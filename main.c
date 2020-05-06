#include <stdio.h>
#include <stdlib.h>
#include "hashmap.c"

int main() {
  struct HashMap *map = newMap();
  int i1 = 1;
  int i2 = 2;
  int i3 = 3;
  put(map, 1, &i1);
  put(map, 2, &i2);
  put(map, 3, &i3);
  int *h1 = get(map, 1);
  int *h2 = get(map, 2);
  int *h3 = get(map, 3);
  printf("%d", *h2);
  printf("%d", *h1);
  printf("%d", *h3);
  freeMap(map);
  return 0;
}