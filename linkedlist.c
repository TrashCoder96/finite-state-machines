#include <stdio.h>
#include <stdlib.h>

struct LinkedListNode {
    void *value;
    struct LinkedListNode *next;
};

struct LinkedList {
    struct LinkedListNode *head;    
};

void pushItem(struct LinkedList *list, int *value) {
    struct LinkedListNode *newItem = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
    newItem->value = value;
    newItem->next = list->head;
    list->head = newItem;
}

void removeItem(struct LinkedList *list, int *value) {
    if (!list->head) {
        struct LinkedListNode *beforeItem = NULL;
        struct LinkedListNode *item = list->head;
        while (item->value != value || !item) {
            beforeItem = item;
            item = item->next;
        }
        if (!item) {
            if (list->head == item) {
                list->head = item->next;
            } else {
                beforeItem->next = item->next;
            }
            free(item);
        }
    }
}

