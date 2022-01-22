/* ========== Operations for linked lists ========== */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "structures.h"

/* ----- Node creation ----- */

NODE *createNode(int data);

/* ----- Add operations ----- */

// At the beggining
int addNodeStart(NODE **head, NODE **tail, int data);

// At a certain position
int addNodeMid(NODE **head, NODE **tail, int data, int position);

// At the end
int addNodeEnd(NODE **head, NODE **tail, int data);

/* ----- Delete operations ----- */

// From the beggining
int delNodeStart(NODE **head, NODE **tail);

// At a certain position
int delNodeMid(NODE **head, NODE **tail, int position);

// From the end
int delNodeEnd(NODE **head, NODE **tail);

/* ----- Miscellaneous operations ----- */

// Reverse the order of the list
int reverseNodes(NODE **head, NODE **tail);

// Swap the position of two nodes
int swapNodes(NODE **head, NODE **tail, int posNode1, int posNode2);

// Create a circular list
int circularNodes(NODE **head, NODE **tail);

#endif