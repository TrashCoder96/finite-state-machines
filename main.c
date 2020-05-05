#include <stdio.h>
#include <stdlib.h>
#include "hashmap.c"

int main() {
  struct HashMap *map = newMap();
  //struct LinkedList *newList = (struct LinkedList*)malloc(sizeof(struct LinkedList));
  //map->buckets[8] = newList;
  freeMap(map);
  return 0;
}