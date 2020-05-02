#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
    struct LinkedListNode* head;    
};

struct LinkedListNode {
    void* value;
    struct LinkedListNode* next;
};

void pushItem(struct LinkedList* list, void* value) {
    struct LinkedListNode* newItem = malloc(sizeof(struct LinkedListNode));
    newItem->value = value;
    newItem->next = list->head;
    list->head = newItem;
}

void removeItem(struct LinkedList* list, void* value) {
    if (list->head != NULL) {
        struct LinkedListNode* beforeItem = NULL;
        struct LinkedListNode* item = list->head;
        while (item->value != value || item != NULL) {
            beforeItem = item;
            item = item->next;
        }
        if (item != NULL) {
            if (list->head == item) {
                list->head = item->next;
            } else {
                beforeItem->next = item->next;
            }
            free(item);
        }
    }
}

