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
        map->buckets[i] = (struct LinkedList*)malloc(sizeof(struct LinkedList));
        map->buckets[i]->head = NULL;
    }
    return map;
};

int hash(int key) {
     return key % INITIAL_CAPACITY;
 }

void freeMap(struct HashMap *map) {
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        free(map->buckets[i]);
    }
    free(map->buckets);
    free(map);
}

void put(struct HashMap *map, int key, int *value) {
    struct LinkedList *bucket = map->buckets[hash(key)];
    pushItem(bucket, key, value);
}

int *get(struct HashMap *map, int key) {
    struct LinkedList *bucket = map->buckets[hash(key)];
    return find(bucket, key);
}

