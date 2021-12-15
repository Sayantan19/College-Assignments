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

void delMidIndex(node * n,int index)
{
    if(head==NULL)
        printf("No elements to be deleted\n");
    else
    {
        node * p = (node *)malloc(sizeof(node));
        p = head;
        for(int i=0;i<index-1;i++)
            p = p->next;
        p->next = p->next->next;
    }
}

void delMidValue(node * n,int indexValue)
{
    if(head==NULL)
        printf("No elements to be deleted\n");
    else
    {
        node * p = (node *)malloc(sizeof(node));
        p = head;
        while(p->data!=indexValue)
            p = p->next;
        p->next = p->next->next;
    }
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
    int n,x,index,value,indexValue;
    printf("Enter an element: ");
    scanf("%d",&n);
    head = create(n);
    for(int i=0;i<3;i++)
    {
        printf("Enter the element to be entered: ");
        scanf("%d",&x);
        insertEnd(head,x);
    }
    display(head);
    printf("\nEnter the index you want to delete the element from: ");
    scanf("%d",&index);
    delMidIndex(head,index); 
    printf("The element can be displayed as\n");
    display(head);
    printf("\nEnter the value after which you want to delete the element from: ");
    scanf("%d",&indexValue);
    delMidValue(head,indexValue);
    display(head);
    return 0;
}