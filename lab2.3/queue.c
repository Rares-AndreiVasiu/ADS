#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct node
{
    int val;

    struct node *next;

} Node;

typedef struct queue
{
    Node *head;
    Node *tail;
} Queue;

Queue create_queue()
{
    Queue q;

    q.head = NULL;

    q.tail = NULL;

    return q;
}

void fatal(char *msg)
{
    perror(msg);

    exit(EXIT_FAILURE);
}

void push(Queue *q, int x)
{
    Node *localNode = (Node *) malloc(sizeof(Node));

    if(!localNode)
    {
        fatal("Error while allocating memory!");
    }

    localNode -> val = x;
    
    localNode -> next = NULL;

    /*
        if the queue is empty we add the first element to the front
        of the queue
    */

    if (!q->head)
    {
        q -> head = localNode;

        q -> tail = localNode;
    }
    else
    {
        //otherwise add it to the end of the queue
        q -> tail -> next = localNode;

        q -> tail = localNode;
    }
}

int pop(Queue *q)
{
    // check if queue has >= 1 elements
    if (!q -> head)
    {
        printf("Queue is empty.Cannot pop any element\n");

        return -1;
    }

    Node *targetNode = q -> head;

    //we may want to find the popped value
    int popped_val = targetNode -> val;

    q -> head = targetNode -> next;

    //got to free the usless pointer targetNode
    free(targetNode);

    if (!q -> head)
    {
        q -> tail = NULL;
    }

    return popped_val;
}

void print(Queue *q)
{
    if (!q -> head)
    {
        printf("Queue is empty. There is nothing but emptyness to print.\n");
        return;
    }

    //create a copy of the head of queue
    Node *front = q -> head;

    //printf("The elements of the queue are: ");
    //loop untill we reach the end element, front is not NULL
    while (front != NULL)
    {
        printf("%d\n", front -> val);

        front = front -> next;
    }

    //we need a newline to keep things tidy =)
    //printf("\n");
}
