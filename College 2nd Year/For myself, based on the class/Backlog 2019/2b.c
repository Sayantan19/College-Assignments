#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *create(int);
node *InsertEnd(node *, int);
int IsSort(node * );
void display(node *);

void main()
{
    int n;
    node *head = NULL;
    printf("Enter the first element: ");
    scanf("%d", &n);
    head = create(n);
    do
    {
        printf("Enter the next element: ");
        scanf("%d", &n);
        InsertEnd(head, n);
        printf("Do you want to add more elements: ");
        scanf("%d", &n);
        if(n==0)
            break;
    } while (1);
    // display(head);
    int check = IsSort(head);
    if(check==1)
        printf("Sorted (in Ascending order)\n");
    else
        printf("Not sorted!\n");
}

node * create(int n)
{
    node * temp = (node *)malloc(sizeof(node));
    temp->data = n;
    temp->next = NULL;
    return temp;
}

node * InsertEnd(node * head,int n)
{
    node * p = head;
    while(p->next!=NULL)
        p = p->next;
    node * temp = create(n);
    p->next = temp;
    return p;
}

int IsSort(node * head)
{
    node * p = head;
    while(p->next!=NULL)
    {
        if(p->next->data-p->data<0)
            return 0;
        p = p->next;
    }
    return 1;
}

void display(node * head)
{
    node *p;
    p = head;
    if(p == NULL)
    {
        printf("Empty set\n");
        return;
    }
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
}