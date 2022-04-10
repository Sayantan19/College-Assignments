#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    struct Node * next;
    int data;
    struct Node * prev;
}node;

node * create(int a)
{
    node * n = (node *)malloc(sizeof(node));
    n->next = NULL;
    n->data = a;
    n->prev = NULL;
    return n;
}

void display(node * head)
{
    node * p = head;
    if(head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    printf("Prev\t\tData\t\tNext\n");
    while(p!=NULL)
    {
        printf("%p\t%d\t%p\n",p->prev,p->data,p->next);
        p = p->next;
    }
}

node * InsertEnd(node * head,int a)
{
	node * temp = create(a);
	node * p = head;
	if(head == NULL)
		head = temp;
	else
	{
		while(p->next!=NULL)
			p = p->next;
		p->next = temp;
		temp->prev = p;
	}
	return head;
}


int main()
{
    node * head;
    int x;
    printf("Enter the 1 element: ");
    scanf("%d",&x);
    head = create(x);
    for(int i=1;i<5;i++)
    {
        printf("Enter the %d element: ",(i+1));
        scanf("%d",&x);
        head = InsertEnd(head,x);
    }
    display(head);
    return 0;
}