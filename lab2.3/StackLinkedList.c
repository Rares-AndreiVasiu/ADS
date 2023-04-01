#include <stdio.h>
#include <stdlib.h>
typedef struct node 
{
    int data;

    struct node *next;

} Node;

typedef struct stack 
{
    Node *head;

} Stack;

Stack create_stack()
{
    Stack beta;
    
    beta.head = NULL;

    return beta;
}

void push(Stack *s, int x)
{
    Node *newNode = (Node *) malloc(sizeof(Node));

    newNode -> data = x;
    
    newNode -> next = s -> head;
    
    s -> head = newNode;
}

int pop(Stack *s)
{
    if (s->head == NULL)
    {
        return -1;
    }

    int data = s -> head -> data;

    Node *temp = s -> head;

    s -> head = s -> head -> next;

    free(temp);
    
    return data;
}

void print(Stack *s)
{
    Node *current = s -> head;

    while (current != NULL) 
    {
        printf("%d\n", current -> data);
    
        current = current -> next;
    }
}
