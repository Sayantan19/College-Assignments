#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node *head;

void create(int);
void traverse();

int main()
{
    int c,n;
    printf("Enter the number of elements of the linked list: ");
    scanf("%d",&n);
    create(n);
    traverse();
}

void create(int n)
{
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    head=p;
    if(p==NULL)
    {
        printf("Overflow\n");
        return;
    }
    if(head==NULL)
    {
        p->data = n;
        p->next=NULL;
        // p->prev=NULL;
        head = p;

    }
    else
    {
        p->data = n;
        p->next = head;
        head = p;
        printf("Node inserted\n");
    }
}

void traverse()
{
    struct Node *p;
    p = head;
    if(p == NULL)
    {
        printf("Empty set\n");
        return;
    }
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}