#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
} node;

node * Insert(node *);
node * Delete(node *);
node * create(int);
node * InsertBeg(node *, int);
node * InsertMid(node *, int);
node * InsertMidBefore(node *, int, int);
node * InsertMidAfter(node *, int, int);
node * InsertEnd(node *, int);
node * DelMidBefore(node *,int);
node * DelMidAfter(node *,int);
node * DelBeg(node *);
node * DelEnd(node *);
void display(node *);

int main()
{
	int choice,x;
	node * n;
	do
	{	
		printf("1 for Create\n2 for Insert\n3 for Delete\n4 for Display\n5 for Exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:		printf("Enter the element with wich you want to create the List: ")	;
						scanf("%d",&x);
						n = create(x);
						printf("Node created successfully!\n");
						break;

			case 2:		printf("Welcome to Insertion Operation!\n");
						n = Insert(n);
						break;
			
			case 3: 	printf("Welcome to Deletion Operation!\n");
						n = Delete(n);
						break;

			case 4:		display(n);
						break;

			case 5:		return 0;
						break;
			
			default:	printf("Wrong choice!\n");
		}
	}while(1);
	return 0;
}

node * Insert(node * n)
{
	int choice,element,target;
	printf("Enter the element to be inserted: ");
	scanf("%d",&element);
	printf("1 for Insertion in the beginning\n2 for Insertion at the end\n3 for Insertion before target element\n4 for Insertion after target element\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:		n = InsertBeg(n,element);
					break;
		case 2:		n = InsertEnd(n,element);
					break;
		case 3:		printf("Enter the target element: ");
					scanf("%d",&target);
					n = InsertMidBefore(n,target,element);
					break;
		case 4:		printf("Enter the target element: ");
					scanf("%d",&target);
					n = InsertMidAfter(n,target,element);
					break;
	}
	return n;
}

node * Delete(node * n)
{
	int choice,target;
	printf("1 for Deletion in the beginning\n2 for Deletion at the end\n3 for Deletion before target element\n4 for Deletion after target element\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:		n = DelBeg(n);
					break;
		case 2:		n = DelEnd(n);
					break;
		case 3:		printf("Enter the target element: ");
					scanf("%d",&target);
					n = DelMidBefore(n,target);
					break;
		case 4:		printf("Enter the target element: ");
					scanf("%d",&target);
					n = DelMidAfter(n,target);
					break;
	}
	return n;
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
	head->prev = NULL;
    head->next->prev = head;
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
		// printf("%p",p->prev);
	}
	return head;
}

node * DelMidAfter(node * head,int target)
{
	node * p = head;
	if(!Search(head,target))
	{
		printf("Element not found. Cannot delete!\n");
		return head;
	}
	while(p->data != target)
		p = p->next;
	if(p->next == NULL)
		printf("There is no element after this. Cannot delete!\n");
	else if(p->next->next == NULL)
		DelEnd(head);
	else
	{
		p = p->next;
		(p->next)->prev = p->prev;
		(p->prev)->next = p->next;
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