#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}node;

node * head;

node * create(int n)
{
    node * temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = n;
    temp->next = NULL;
    return temp;
}

node * insertEnd(node * n,int value)
{
    node * temp = create(value);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        node * p = (node *)malloc(sizeof(node));
        p = head;
        while(p->next!=NULL)
            p = p->next;
        p->next=temp;
    }
}

void display(node * n)
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
        printf("%d\t%p\n",p->data,p->next);
        p = p->next;
    }
}

int main()
{
    int n,x;
    printf("Enter an element: ");
    scanf("%d",&n);
    head = create(n);
    printf("Enter the element to be entered: ");
    scanf("%d",&x);
    insertEnd(head,x);
    printf("The element can be displayed as\n");
    display(head);
    return 0;
}