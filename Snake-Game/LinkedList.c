#include "LinkedList.h"

LinkedList* makeList() /*Makes linked List*/
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

/*Inserts new node at the front of the list*/
void insertFirst(LinkedList* list, void* inData)
{
    Node* pNode = (Node*)malloc(sizeof(Node)); /*Makes new node*/
    
    pNode->next = NULL;
    pNode->prev = NULL;
    pNode->data = inData;
    
    if(list->head == NULL) /*If the linked list is empty, pNode*/
    {
        list->head = pNode;
    }
    else
    {
        pNode->next = list->head; /*points to next node as pNode is the current start of the list*/
        list->head->prev = pNode; /*The previous heads previous point is changed to the pNode*/
        list->head = pNode; /*New head of the linked list*/
    }
    list->size++; /* The size of the linked list increases*/
}

/*Adds a new node at the end of the list*/
void insertLast(LinkedList* list, void* inData)
{
    Node* pNode = (Node*)malloc(sizeof(Node)); /*Makes new node*/
    pNode->next = NULL;
    pNode->prev = NULL;
    pNode->data = inData;
    
    if(list->tail == NULL) /*If the linked list is empty, pNode will be the head*/ 
    {
        list->head = pNode;
        list->tail = pNode;
    }
    else
    {
        pNode->prev = list->tail; /*Points to prev node as pNode is current tail */
        list->tail->next = pNode; /* The previous tail is the 2nd last node in the list after the pNode */
        list->tail = pNode; /*new tail of the linked list*/
    }
    list->size++; /*The size of the linked list increases*/
}

/*Removes the current head node*/
void* removeFirst(LinkedList* list)
{
    void* nodeData;
    Node* node;
    if(list->head == NULL) 
    {
        nodeData = NULL; /*returns the data of the first node/NULL if the linked list is currenty empty*/
    }
    else
    { 
        node = list->head; /*node points to the first node*/
        nodeData = node->data; /*nodeData is updated with the data of the node to be removed*/
        list->head = list->head->next; /*head of the list is updated to the previous node*/
        list->size--; /*the linked list size is decreased as we have removed a node*/
    }
    return nodeData;
}

/*Removes the current tail node*/
void* removeLast(LinkedList* list)
{
    Node* node;
    void* nodeReturn = 0;

    if(list->size == 0)
    {
        node = NULL;
    }
    else 
    {
        nodeReturn = list->tail->data; /*The deleted node will be the current tail*/
        list->tail = list->tail->prev; /*New tail of the list is the previous one from the current tail*/
        list->tail->next = NULL;
        list->size--; /*The linked list decreases as you're removing the tail*/
    }
    return nodeReturn;
}

/*Free linked list*/
/*This method was taken from - BlackBoard - FAQ - Structs*/
void freeLinkedList(LinkedList* list, listFunc fptr)
{
    Node* currentNode = list->head;
    Node* temp;
    while(currentNode)
    {
        temp = currentNode->next;
        (*fptr)(currentNode->data);
        currentNode->data = NULL;
        currentNode->next = NULL;
        free(currentNode);
        currentNode = temp;    
    }
    free(list);
}

/*Free node*/
void freeNode(void* data)
{
    free(data);
    data = NULL;
}

