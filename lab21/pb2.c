#include<stdio.h>

typedef struct node 
{
	int val;

	struct node *next;

} node;

typedef struct list 
{
	node *head;

} list;

void print(list l)
{
	/*while(l.head != NULL)
	{
		printf("%d ", l.head->val);

		l.head->next = ;
	}*/
	if(l.head==NULL)
		return;
	printf("%i ",l.head->val);
	l.head=l.head->next;
	print(l);
}
