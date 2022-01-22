/* ========== Operations for linked lists ========== */

#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"

/* ----- Node creation ----- */

NODE *createNode(int data){

    NODE *tempNode = (NODE *)malloc(sizeof(NODE));

    if(!tempNode)
        return(NULL);

    tempNode->data = data;
    tempNode->prevNode = NULL;
    tempNode->nextNode = NULL;

    return(tempNode);

}

/* ----- Add operations ----- */

// At the beggining
int addNodeStart(NODE **head, NODE **tail, int data){

    NODE *tempNode = createNode(data);

    if(!tempNode)
        return(EXIT_FAILURE);

    if(*head == *tail && !*head){ // If the list is empty
        
        *head = tempNode;
        *tail = tempNode;

    }

    else{   // If the list isn't empty

        tempNode->nextNode = *head;
        (*head)->prevNode = tempNode;
        *head = tempNode;

    }

    if(*head == tempNode)   // Check for errors
        return(EXIT_SUCCESS);
    else
        return(EXIT_FAILURE);

}

// At a certain position
int addNodeMid(NODE **head, NODE **tail, int data, int position){

    NODE *previous = *head, *next, *tempNode = createNode(data);

    if(!tempNode)
        return(EXIT_FAILURE);

    if(position == 0) // If the position is 0
        return(addNodeStart(head, tail, data));

    else if(position > 0 && *head && *tail){     // If position in non-negative and the list isn't empty
    
        for(int i = 0; i < position - 1; i++){
        
            previous = previous->nextNode;

            if(!previous)   // If the n'th element doesn't exist
                return(EXIT_FAILURE);

        }

        next = previous->nextNode;

        if(!next)  // If the element will be at the end
            return(addNodeEnd(head, tail, data));

        tempNode->nextNode = next;
        tempNode->prevNode = previous;
        previous->nextNode = tempNode;
        next->prevNode = tempNode;

        if(previous->nextNode == tempNode && next->prevNode == tempNode)    // Check for errors
            return(EXIT_SUCCESS);
        else
            return(EXIT_FAILURE);

    }

    else    // The position was negative
        return(EXIT_FAILURE);

}

// At the end
int addNodeEnd(NODE **head, NODE **tail, int data){

    NODE *tempNode = createNode(data);

    if(!tempNode)
        return(EXIT_FAILURE);

    if(*head == *tail && !*tail){ // If the list is empty
        
        if(addNodeStart(head, tail, data) == EXIT_SUCCESS)
            return(EXIT_SUCCESS);
        else
            return(EXIT_FAILURE);

    }

    else{   // If the list isn't empty
                   
        tempNode->prevNode = *tail;
        (*tail)->nextNode = tempNode;
        *tail = tempNode;

    }

    if(*tail == tempNode)   // Check for errors
        return(EXIT_SUCCESS);
    else
        return(EXIT_FAILURE);

}