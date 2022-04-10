#include<stdio.h>
#include<stdlib.h>

struct DLLNode
{
    struct DLLNode * prev;
    int data;
    struct DLLNode * next;
};

struct DLLNode *Head;

int main()
{
    
}

void push1(struct DLLNode* head,int n)
{
    struct DLLNode* temp = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    temp->data = n;
    temp->next = head;
    temp->prev = NULL;
    if(head==NULL)
        head = temp;
}

void push2(struct DLLNode *node1,int n)
{
    if(node1==NULL)
    {   printf("Not possible");
        return;
    }
    struct DLLNode *Head;
    struct DLLNode* temp = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    struct DLLNode *p;
    p = Head;
    for(int i=0;i<n-1;i++)
        p = p->next;
    temp->next = p->next;
    temp->prev=p;
    p->next->prev = temp;
    p->next = temp;
}