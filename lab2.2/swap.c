#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;

    struct node *next;

}node;

typedef struct list
{
    node * head;

}list;

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
    node *last = l -> head;

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


void swap(list *l, int k)
{
    node *current = l->head;

    if(current == NULL)
    {
        return;
    }

    int lengthList = 0;

    while(current != NULL)
    {
        printf("Elements: %d\n", current->val);

        lengthList++;

        current = current -> next;
    }

    printf("List length: %d\n", lengthList);

    if(k < 0 || k > lengthList)
    {
        return;
    }

    node *firstK = l -> head;

    node *lastK = l -> head;

    for(int i = 0; i < k; ++ i)
    {
        firstK = firstK ->next;
    }

    for(int i = 0; i < lengthList - k - 1; ++ i)
    {
        lastK = lastK -> next;
    }

    //exchange the values of these pointers

    int auxilary = firstK -> val;

    printf("First: %d, Last: %d\n", auxilary, lastK->val);

    firstK->val = lastK -> val;

    lastK -> val = auxilary;
}

list l1;

int main(){
    
    int i = 0, x;
    
    int n, k;
    
    scanf("%d %d", &n, &k);
    
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &x);

        append(&l1, x);
    }

    swap(&l1, k);
    
    print(l1);
}
