#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node * next;
};

int count(struct Node * head)
{
	int c;
	if(head==NULL)
		return 0;
	else
	{
		c=0;
		struct Node * temp = head;
		while(temp!=NULL)
		{
			c++;
			temp = temp->next;
		}
		return c;
	}
}

struct Node * create(int data)
{
	struct Node * temp;
	temp = (struct Node *) malloc (sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	
	return temp;
}

struct Node * construct()
{
	int n,x;
	printf("Enter the number of nodes to be inserted: ");
	scanf("%d",&n);
	struct Node * head;
	head = NULL;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(head!=NULL)
		{	
			head = create(x);
		}
		else 
		{
			head = insertEnd(head,x);
		}
	}
	return head;
}

struct Node * create2(struct Node * head)
{
	int c;
	struct Node * temp, * change;
	if(head!=NULL)
		printf("List already exists\n");
	else
	{
		do
		{
			temp = (struct Node *)malloc(sizeof(struct Node));
			temp->next = NULL;
			scanf("%d",&temp->data);
			if(head == NULL)
			{
				head = temp;
				change = temp;
			}
			else
			{
				change->next = temp;
				change = temp;
			}
			printf("1 for more 0 for none");
			scnaf("%d",&c);
		}while(c);
	}
	return head;
}

struct Node * insertBeg(struct Node * head, int value)
{
	struct Node * temp = NULL;
	int x;
	if(head == NULL)
	{		
		head = create(value);
	}
	else
	{
		temp = (struct Node *) malloc (sizeof(struct Node));
		temp->data=value;
		temp->next=head;
		head = temp;
	}		
	return head;
}

struct Node * insertEnd(struct Node * head, int value)
{
	struct Node * temp, * change;
	if(head == NULL)
	{
		head = create(value);
	}
	else
	{
		temp = (struct Node *) malloc (sizeof(struct Node));
		temp->next=NULL;
		printf("Enter the element to be inserted at the end");
		scanf("%d",&temp->data);
		change = head;
		while(change->next!=NULL)
			change=change->next;
		change->next = temp;
	}		
	return head;
}

struct Node * insertnth(struct Node * head)
{
	struct Node * temp,* change	;
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	if((n<1)||n>count(head)+1)
	{
		printf("Invalid number\n");
		scanf("%d",&n);
	}
	if(n==1)
		head = insertBeg(head);
	else
	{
		change = head;
		for(int i=0;i<n-1;i++)
			change = change->next;
		temp->next = change -> next;
		change -> next = temp;
	}		
	return head;
}


