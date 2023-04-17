#include <stdio.h>
#include <string.h>
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

void merge(list *dest, list *l1, list *l2) 
{
    node *cur1 = l1 -> head;

    node *cur2 = l2 -> head;

    // Set up the head of the merged list
    if (cur1 -> val < cur2 -> val) 
    {
        dest -> head = cur1;

        cur1 = cur1 -> next;
    } 
    else 
    {
        dest -> head = cur2;

        cur2 = cur2 -> next;
    }

    node *cur_dest = dest -> head;

    // Merge the two lists
    while (cur1 != NULL && cur2 != NULL) 
    {
        if (cur1 -> val < cur2 -> val) 
        {
            cur_dest -> next = cur1;

            cur_dest = cur1;
            
            cur1 = cur1 -> next;
        } 
        else 
        {
            cur_dest -> next = cur2;
            
            cur_dest = cur2;

            cur2 = cur2 -> next;
        }
    }

    // Append any remaining nodes from the non-empty list
    if (cur1 == NULL) 
    {
        cur_dest -> next = cur2;
    } 
    else 
    {
        cur_dest -> next = cur1;
    }
}

void append(list *l, int k)
{
    node *last = l->head;

    while(l->head != NULL && last->next != NULL)
    {
        last = last -> next;
    }

    node *append = malloc(sizeof(node));

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

void print(list l)
{
    node *current;

    for(current = l.head; current != NULL; current = current ->next)
    {
        printf("%d ", current->val);
    }
}

list l1, l2, l3;

int main()
{

    int i = 0, j = 0, x;

    while (i < 5)
    {
        scanf("%d", &x);
    
        i ++;
    
        append(&l1, x);
    }
    
    while (j < 7)
    {
        scanf("%d", &x);
    
        j ++;
    
        append(&l2, x);
    }

    merge(&l3, &l1, &l2);
    
    print(l3);
}
