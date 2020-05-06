#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct LinkedListNode {
    int key;
    int *value;
    struct LinkedListNode *next;
};

struct LinkedList {
    struct LinkedListNode *head;    
};

int *find(struct LinkedList *list, int key) {
    struct LinkedListNode *item = list->head;
    while (item->key != key && item != NULL) {
        item = item->next;
    }
    if (item != NULL) {
        return item->value;
    } else {
        return NULL;
    }
}

void pushItem(struct LinkedList *list, int key, int *value) {
    struct LinkedListNode *newItem = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
    newItem->key = key;
    newItem->value = value;
    newItem->next = list->head;
    list->head = newItem;
}

void removeItem(struct LinkedList *list, int key) {
    if (!list->head) {
        struct LinkedListNode *beforeItem = NULL;
        struct LinkedListNode *item = list->head;
        while (item->key != key && item != NULL) {
            beforeItem = item;
            item = item->next;
        }
        if (item != NULL) {
            if (list->head == item) {
                list->head = item->next;
            } else {
                beforeItem->next = item->next;
            }
            free(item->value);
            free(item);
        }
    }
}

