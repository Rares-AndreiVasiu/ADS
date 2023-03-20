#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
	int val;

	struct node *next;
} node;

typedef struct _list
{
	node *head;
}list;

void print(list l)
{
	if(l.head == NULL)
		return;

	printf("%d ", l.head->val);

	l.head = l.head->next;

	print(l);
}

void prepend(list *l, int k)
{
    node* my_way=malloc(sizeof(struct node));
    
    my_way->val=k;
    
    my_way->next=l->head;
    
    l->head=my_way;
}
