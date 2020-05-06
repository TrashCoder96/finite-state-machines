#include <stdio.h>
#include <stdlib.h>
#include "hashmap.c"

int main() {
  struct HashMap *map = newMap();
  for (int i = 10; i < 100; i++) {
    int *num = (int*)malloc(sizeof(int));
    *num = i;
    put(map, i, num);
  }
  rem(map, 78);
  for (int i = 10; i < 100; i++) {
    int *h = get(map, i);
    if (h != NULL) {
      printf("%d\n", *h);
    }
  }
  freeMap(map);
  return 0;
}