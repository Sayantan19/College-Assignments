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

node * DelEnd()
{
    if(head==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        node * p = (node *)malloc(sizeof(node));
        p = head;
        if(head->next==NULL)
            head = NULL;
        else
        {
            while(p->next->next!=NULL)
                p = p->next;
            p->next = NULL; 
        }

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
    int n,x;
    printf("Enter an element: ");
    scanf("%d",&n);
    head = create(n);
    for(int i=0;i<3;i++)
    {
        printf("Enter the element to be entered: ");
        scanf("%d",&x);
        insertEnd(head,x);
    }
    DelEnd();
    printf("The elements after deletion can be displayed as\n");
    display(head);
    return 0;
}