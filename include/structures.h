/* ========== Structures for all Data Structures ========== */

#ifndef STRUCTURES_H
#define STRUCTURES_H

// For linked lists, stacks and queues
typedef struct node{

    int data;
    struct node *nextNode;
    struct node *prevNode;

} NODE;

#endif