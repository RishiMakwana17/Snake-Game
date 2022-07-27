#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST
#define LINKEDLIST

typedef void (*listFunc)(void* data);

typedef struct Node
{
    struct Node* next;
    struct Node* prev;
    void* data;

}Node;

typedef struct LinkedList
{
    Node* head;
    Node* tail;
    int size;
}LinkedList;

LinkedList* makeList();
void insertFirst(LinkedList* list, void* inData);
void insertLast(LinkedList* list, void* inData);
void* removeFirst(LinkedList* list);
void* removeLast(LinkedList* list);
void freeLinkedList(LinkedList* list, listFunc fptr);
void freeNode(void* data);
#endif
