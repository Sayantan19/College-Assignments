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
        printf("%d\n",p->data);
        p = p->next;
    }
}

int main()
{
    int n;
    for(int i=0;i<4;i++)
    {
        printf("Enter an element: ");
        scanf("%d",&n);
        head = create(n);
    }
    printf("The element can be displayed as\n");
    display(head);
    return 0;
}