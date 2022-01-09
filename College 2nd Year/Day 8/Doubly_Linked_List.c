#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
} node;

node *create(int);
node *InsertBeg(node *, int);
node *InsertMid(node *, int);
node *InsertMidBefore(node *, int, int);
node *InsertMidAfter(node *, int, int);
node *InsertEnd(node *, int);
node *DelMidBefore(node *,int);
node *DelMidAfter(node *,int);
node *DelBeg(node *);
node *DelEnd(node *);
void display(node *);

int main()
{
	int a;
	// printf("Enter the element: ");
	// scanf("%d",&a);
	node *n = create(56);
	n = InsertBeg(n,67);
	n = InsertEnd(n, 69);
	n = InsertEnd(n, 23);
	display(n);
	// n = InsertMidAfter(n, 56, 23);
	// display(n);
	n = DelMidBefore(n,23);
	display(n);
	return 0;
}

node *create(int n)
{
	node *s = (node *)malloc(sizeof(node));
	s->next = NULL;
	s->data = n;
	s->prev = NULL;
	return s;
}

node *InsertBeg(node *head, int a)
{
	node *temp = create(a);
	if (head == NULL)
		head = temp;
	else
	{
		temp->next = head;
		temp->prev = head;
		head = temp;
	}
	return head;
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

int Search(node *head, int n)
{
	node *p = head;
	while (p->next != NULL)
	{
		if (p->data == n)
			return 1;
		p = p->next;
	}
	if (p->data == n)
		return 1;
	return 0;
}
node *InsertMidBefore(node *head, int target, int a)
{
	node * temp = create(a);
	node *p = head;
	if(!Search(head,target))
		printf("Target element not in the list. Cannot add!");

	else if(head->data==target)
		head = InsertBeg(head,a);

	else
	{
		while(p->next->data!=target)
			p = p->next;
		temp->next = p->next;
		temp->prev = p;
		p->next = temp;
	}
	return head;
}

node * InsertMidAfter(node * head,int target,int a)
{
	node * temp = create(a);
	node *p = head;
	if(!Search(head,target))
		printf("Target element not in the list. Cannot add!\n");
	while(p->data!=target)
		p = p->next;
	if(p->next==NULL)
		p = InsertEnd(p,a);
	else
	{
		temp->next = p->next;
		temp->prev = p;
		p->next = temp;
	}
	return head;
}
node *DelBeg(node *head)
{
	node *p;
	p = head;
	if (head == NULL)
	{
		printf("Underflow!\n");
		return head;
	}
	else if (head->next == NULL)
		head = NULL;
	else
	{
		head = p->next;
	}
	return head;
}

node * DelEnd(node * head)
{
	node * p;
	p = head;
	if (head == NULL)
	{
		printf("Underflow!\n");
		return head;
	}
	else if (head->next == NULL)
		head = NULL;
	else
	{
		while(p->next->next!=NULL)
			p = p->next;
		p->next=NULL;
	}
	return head;
}

node * DelMidBefore(node * head,int target)
{
	node * p = head;
	if(!Search(head,target))
		printf("Target element not found. Cannot delete!\n");
	else if(head->data == target)
		printf("There is no element before this. Cannot delete!\n");
	else
	{
		while(p->next->data!=target)
			p = p->next;
			// p = p->next;
		(p->next)->prev = p->prev;
		(p->prev)->next = p->next;
		printf("%p",p->prev);
	}
	return head;
}

void display(node *start)
{
	node *p;
	p = start;
	if (start == NULL)
	{
		printf("\nList is Empty.");
	}
	else
	{
		printf("\nThe element(s) are:");
		while (p != NULL)
		{
			printf(" %d", p->data);
			p = p->next;
		}
	}
	printf("\n");
}