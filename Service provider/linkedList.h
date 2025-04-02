//
// Created by USER on 3/29/2025.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    void* value;
    struct node* next;
} node;

typedef struct linkedList {
    node* head;
    node* tail;
    int _size;
} linkedList;

typedef struct {
    void* key;
    void* val;
} keyValPair;

linkedList* createList();
void appendToList(linkedList* l, void* value);
void* removeFirst(linkedList* l);
void* getValueAt(linkedList* l, int index);
void freeList(linkedList* l, bool freeValues);

#endif // LINKED_LIST_H
#endif //LINKEDLIST_H
