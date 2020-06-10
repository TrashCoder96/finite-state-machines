#include <stdio.h>
#include "linkedlist.c"

#define INITIAL_CAPACITY 16

struct HashMap {
    struct LinkedList *buckets; //array of linked lists
};

struct HashMap *newMap() {
    struct HashMap *map = (struct HashMap*)malloc(sizeof(struct HashMap));
    map->buckets = malloc(INITIAL_CAPACITY * sizeof(struct LinkedList));
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        map->buckets[i].head = NULL;
    }
    return map;
};

int hash(char key) {
    return (int)key % INITIAL_CAPACITY;
}

void freeMap(struct HashMap *map) {
    free(map->buckets);
    free(map);
}

void put(struct HashMap *map, char key, struct State *value) {
    struct LinkedList *bucket = &(map->buckets[hash(key)]);
    pushItem(bucket, key, value);
}

struct State *get(struct HashMap *map, char key) {
    struct LinkedList *bucket = &(map->buckets[hash(key)]);
    return find(bucket, key);
}

void rem(struct HashMap *map, char key) {
    removeItem(&(map->buckets[hash(key)]), key);
}
