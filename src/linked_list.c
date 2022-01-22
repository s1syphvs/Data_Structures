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