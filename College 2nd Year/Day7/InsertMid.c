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

node * insertMidIndex(node * n,int index,int value)
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
        for(int i=0;i<index-1;i++)
            p = p->next;
        temp->next = p->next; 
        p->next=temp;
    }
}

node * insertMidValue(node * n,int indexValue,int value)
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
        while(p->data!=indexValue)
            p = p->next;
        temp->next = p->next; 
        p->next=temp;
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
    printf("\nEnter the index you want to insert the element at: ");
    scanf("%d",&index);
    printf("Enter the value you want to insert: ");
    scanf("%d",&value);
    insertMidIndex(head,index,value); 
    printf("The element can be displayed as\n");
    display(head);
    printf("\nEnter the value after which you want to insert the element at: ");
    scanf("%d",&indexValue);
    printf("Enter the value you want to insert: ");
    scanf("%d",&value);
    insertMidValue(head,indexValue,value);
    display(head);
    return 0;
}