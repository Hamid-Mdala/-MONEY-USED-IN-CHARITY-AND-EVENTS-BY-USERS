//
// Created by USER on 3/29/2025.
//
#include "linkedList.h"

linkedList* createList() {
    linkedList* l = (linkedList*)malloc(sizeof(linkedList));
    l->head = NULL;
    l->tail = NULL;
    l->_size = 0;
    return l;
}

void appendToList(linkedList* l, void* value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    if (l->tail) {
        l->tail->next = newNode;
    } else {
        l->head = newNode;
    }
    l->tail = newNode;
    l->_size++;
}

void* removeFirst(linkedList* l) {
    if (!l->head) return NULL;
    node* first = l->head;
    void* value = first->value;
    l->head = first->next;
    if (!l->head) {
        l->tail = NULL;
    }
    free(first);
    l->_size--;
    return value;
}

void* getValueAt(linkedList* l, int index) {
    if (index < 0 || index >= l->_size) return NULL;
    node* current = l->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->value;
}

void freeList(linkedList* l, bool freeValues) {
    node* current = l->head;
    while (current) {
        node* next = current->next;
        if (freeValues) {
            free(current->value);
        }
        free(current);
        current = next;
    }
    free(l);
}