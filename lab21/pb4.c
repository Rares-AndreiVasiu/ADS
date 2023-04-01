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
    if(!l.head)
    {
        return;
    }

    printf("%d ", l.head->val);

    l.head = l.head -> next;

    print(l);
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
