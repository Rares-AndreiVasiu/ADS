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

void delete(list *l, int k)
{
    node* current = l->head, *previous;

    if(current != NULL && current ->val == k)
    {
        l->head = current -> next;
        free(current);
        return;
    }
    
    while(current != NULL && current ->val != k)
    {
        previous = current;

        current = current -> next;
    }    

    if(current == NULL)
    {
        return;
    }

    previous ->next = current ->next;
    free(current);
}
