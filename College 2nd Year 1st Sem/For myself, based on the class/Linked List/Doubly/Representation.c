#include<stdio.h>
#include<stdlib.h>

struct DLLNode
{
    struct DLLNode * prev;
    int data;
    struct DLLNode * next;
};

struct DLLNode *head;

void create(int n)
{
    struct DLLNode *ptr = (struct DLLNode *)malloc(sizeof(struct DLLNode));
    if(ptr == NULL)
    {
        printf("Overflow\n");
        return;
    }
    if(head==NULL)
    {
        ptr->data = n;
        ptr->next=NULL;
        ptr->prev=NULL;
        head = ptr;

    }
    else
    {
        ptr->data=n;
        ptr->prev=NULL;
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
    }
    printf("Node inserted\n");
}

void traverse()
{
    struct DLLNode *ptr;
    ptr=head;
    if(head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    while(ptr!=NULL)    
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int c,n;
    scanf("%d",&c);
    for(int i=0;i<c;i++)
    {
        scanf("%d",&n);
        create(n);
    }
    traverse();
}
