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

void remove_duplicates(list *l)
{
    node *current = l -> head;

    if(current == NULL)
    {
        return;
    }

    while(current != NULL)
    {
        node* localNode = current;

        while(localNode -> next != NULL)
        {
            if(localNode -> next -> val == current ->val)
            {
                node *auxiliary = localNode ->next;

                // we want to delete the local node which i
                // has duplicate input for the current ndodes

                localNode -> next = localNode -> next -> next;

                free(auxiliary);
            }
            else
            {
                localNode = localNode -> next;
            }
        }
        current = current -> next;
    }
}

list l1;

int main()
{

    int i = 0, j = 0, x;

    while (i < 5)
    {
        scanf("%d", &x);
    
        i++;
    
        append(&l1, x);
    }

    remove_duplicates(&l1);
    
    print(l1);
}
