#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;

    struct node *next;

} node;

typedef struct list
{
    node* head;

} list;

void print(list l)
{
    node *current;

    for(current = l.head; current != NULL; current = current ->next)
    {
        printf("%d ", current->val);
    }
}

void append(list *l, int k)
{
    node *last = l->head;

    while(l->head != NULL && last->next != NULL)
    {
        last = last -> next;
    }

    node *append = malloc(8);

    append ->val = k;

    append ->next = NULL;

    if(l ->head != NULL)
    {
        last ->next = append;
    }
    else
    {
        l->head = append;
    }
}

void insert(list *l, int k, int pos)
{
    int i = 0;

    node *previous = NULL, *newNode, *current;

    newNode = malloc(sizeof(node));

    newNode ->val = k;

    for(current = l->head; current != NULL; current = current->next, i ++)
    {
        if(i >= pos)
        {
            break;
        }
        previous = current;
    }
    
    newNode ->next = current;

    if(previous != NULL)
    {
        previous ->next = newNode;
    }
    else
    {
        current = newNode;
    }
}
