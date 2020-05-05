#include <stdio.h>
#include "linkedlist.c"

#define INITIAL_CAPACITY 16

struct HashMap {
    struct LinkedList **buckets;
};

struct HashMap *newMap() {
    struct HashMap *map = (struct HashMap*)malloc(sizeof(struct HashMap));
    map->buckets = malloc(INITIAL_CAPACITY * sizeof(struct LinkedList*));
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        int i0 = 1;
        int i1 = 2;
        map->buckets[i] = (struct LinkedList*)malloc(sizeof(struct LinkedList));
        pushItem(map->buckets[i], &i0);
        pushItem(map->buckets[i], &i1);
    }
    return map;
};

void freeMap(struct HashMap *map) {
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        free(map->buckets[i]);
    }
    free(map->buckets);
    free(map);
}

void put(int key, int *value) {
    
}

int *get(int key) {
    return NULL;
}

