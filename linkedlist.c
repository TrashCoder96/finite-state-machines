#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct LinkedListNode {
    char key;
    struct State *value;
    struct LinkedListNode *next;
};

struct LinkedList {
    struct LinkedListNode *head;    
};

void freeLinkedList(struct LinkedList *list) {
    struct LinkedListNode *next = list->head;
    struct LinkedListNode *previous = NULL;
    while (next != NULL) {
        previous = next;
        next = next->next;
        free(previous);
    }
    //free(list);
}

struct State *find(struct LinkedList *list, char key) {
    struct LinkedListNode *item = list->head;
    while (item != NULL && item->key != key) {
        item = item->next;
    }
    if (item != NULL) {
        return item->value;
    } else {
        return NULL;
    }
}

void pushItem(struct LinkedList *list, char key, struct State *value) {
    struct LinkedListNode *newItem = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
    newItem->key = key;
    newItem->value = value;
    newItem->next = list->head;
    list->head = newItem;
}

void removeItem(struct LinkedList *list, char key) {
    if (list->head != NULL) {
        struct LinkedListNode *beforeItem = NULL;
        struct LinkedListNode *item = list->head;
        while (item != NULL && item->key != key) {
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

