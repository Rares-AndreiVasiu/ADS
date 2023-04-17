#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLENGTH 512
#define DBG 0

typedef struct node 
{
    int val;

    struct node *next;

} node;

typedef struct list 
{
    node* head;

} list;

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

void CreateList(list *l, const char *s)
{
    int len = strlen(s);

    node *current = NULL;

    for(int i = len - 1; i >= 0; -- i)
    {
        int digit = s[i] - '0';

        node *newNode = (node *) malloc(sizeof(node));

        newNode -> val = digit;

        newNode ->next = NULL;

        if(current == NULL)
        {
            l ->head = newNode;

            current = newNode;
        }
        else
        {
            current -> next = newNode;

            current = newNode;
        }
    }
}

void printListReversed(node *current)
{
    if(current  == NULL)
    {
        return;
    }

    printListReversed(current -> next);

    printf("%d", current -> val);
}

void print(list l)
{
    node *current = l.head;

    printListReversed(current);
}

void addLists(list *l1, list *l2, list *result)
{
    int carry = 0;

    node *current1 = l1->head;
    
    node *current2 = l2->head;
    
    while (current1 != NULL || current2 != NULL)
    {
        int val1 = (current1 != NULL) ? current1->val : 0;
    
        int val2 = (current2 != NULL) ? current2->val : 0;
    
        int sum = val1 + val2 + carry;
    
        carry = sum / 10;
    
        append(result, sum % 10);
    
        if (current1 != NULL)
            current1 = current1->next;
        if (current2 != NULL)
            current2 = current2->next;
    }

    if (carry > 0)
    {
        append(result, carry);
    }
}

int main()
{
    char num1[MAXLENGTH], num2[MAXLENGTH];

    if(scanf("%511s[^\n]", num1) != 1)
    {   
        return 0;
    }
  
    if(scanf("%511s[^\n]", num2) != 1)
    {
        return 0;
    }

    list l1 = {NULL}, l2 = {NULL}, result = {NULL};

    CreateList(&l1, num1);

    CreateList(&l2, num2);

#if DBG == 1
    print(l1);

    print(l2);
#endif 

    addLists(&l1, &l2, &result);

    print(result);

    return 0;
}
