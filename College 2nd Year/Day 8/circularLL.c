#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

struct node *start = NULL;

struct node *create_cll(struct node *);
struct node *display(struct node *);

struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *start);
struct node *insert_after(struct node *start);

struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *start);


int main()
{
	int j;
	do
	{
		printf("\n 1.Create\n 2.Display\n 3.Insert at front\n 4.Insert at end\n 5.Insert before node\n 6.Insert after node\n 7.Delete from front\n 8.Delete from end\n 9.Delete a target node");
		printf("\n Enter your choice : ");
		scanf("%d",&j);
		switch(j)
		{
			case 1: start = create_cll(start);
					printf("\n Linked list created.");
					break;
		 	case 2: start = display(start);
		 			break;
		 	case 3: start = insert_beg(start);
		 			break;
		 	case 4: start = insert_end(start);
		 			break;
			case 5: start = insert_before(start);
		 			break;
		 	case 6: start = insert_after(start);
		 			break;
		 	case 7: start = delete_beg(start);
		 			break;
		 	case 8: start = delete_end(start);
		 			break;
		 	case 9: start = delete_node(start);
		 			break;
		 	default : printf("\n.....Invalid choice.....\n");
		}
	}
	while(j<10);
	return 0;
}

struct node *create_cll(struct node * start)
{
	struct node *new_node , *ptr;
	int num;
	printf("\n Enter -1 to end \n");
	printf("\n Enter the data : ");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node = (struct node *)malloc(sizeof(struct node *));
		new_node->data = num;
		if(start==NULL)
		{
			new_node->next=new_node;
			start = new_node;
		}
		else
		{
			ptr = start;
			while(ptr->next!=start)
			{
				ptr = ptr->next;
			}
			new_node->next = start;
			ptr->next=new_node;
		}
		printf("\n Enter the data : ");
		scanf("%d",&num);
	}
	return start;
}

struct node *display(struct node * start)
{
	struct node  *ptr;
	ptr = start;
	while(ptr->next!=start)
	{
		printf("\n Value = %d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n Value = %d ",ptr->data);
	return start;
}

struct node *insert_beg(struct node * start)
{
	struct node *new_node , *ptr;
	int num;
	printf("\n Enter the data : ");
	scanf("%d",&num);
	new_node = (struct node *)malloc(sizeof(struct node *));
	new_node->data = num;
	ptr = start;
	while(ptr->next!=start)
	{
		ptr = ptr->next;
	}
	ptr->next=new_node;
	new_node->next=start;
	start = new_node;
	return start;
}

struct node *insert_end(struct node * start)
{
	struct node *new_node , *ptr;
	int num;
	printf("\n Enter the data : ");
	scanf("%d",&num);
	new_node = (struct node *)malloc(sizeof(struct node *));
	new_node->data = num;
	ptr = start;
	while(ptr->next!=start)
	{
		ptr = ptr->next;
	}
	ptr->next=new_node;
	new_node->next=start;
	return start;
}

struct node *insert_before(struct node * start)
{
	struct node *new_node , *ptr , *preptr;
	int num , val;
	printf("\n Enter the value before which you want to enter the data : ");
	scanf("%d",&val);
	new_node = (struct node *)malloc(sizeof(struct node *));
	ptr = start;
	if(ptr->data==val)
	{
		printf("\n Enter the data : ");
		scanf("%d",&num);
		start = insert_beg(start);
	}
	else
	{
		new_node->data=num;
		while(ptr->data!=val)
		{
			preptr=ptr;
			ptr= ptr->next;
		}
		new_node->next = ptr;
		preptr->next = new_node;
	}
	return start;
}

struct node *insert_after(struct node * start)
{
	struct node *new_node , *ptr , *preptr;
	int num , val;
	printf("\n Enter the data : ");
	scanf("%d",&num);
	printf("\n Enter the value before which you want to enter the data : ");
	scanf("%d",&val);
	new_node = (struct node *)malloc(sizeof(struct node *));
	new_node->data=num;
	ptr = start;
	while(preptr->data!=val)
	{
		preptr = ptr;
		ptr = ptr->next;
	}
	new_node->next = ptr;
	preptr->next = new_node;
	return start;
}

struct node *delete_beg(struct node * start)
{
	struct node *ptr ; 
	ptr = start;
	while(ptr->next!=start)
	{
		ptr = ptr->next;
	}
	ptr->next=start->next;
	free(start);
	start = ptr->next;
	return start;
}

struct node *delete_end(struct node * start)
{
	struct node *ptr , *preptr; 
	ptr = start;
	while(ptr->next!=start)
	{
		preptr = ptr;
		ptr = ptr->next;
	}
	preptr->next = ptr->next;
	free(ptr);
	return start;
}

struct node *delete_node(struct node * start)
{
	struct node * ptr , * preptr;
	int val;
	printf("\n Enter the value of node which is to be deleted : ");
	scanf("%d",&val);
	ptr = start;
	if(ptr->data==val)
	{
		start = delete_beg(start);
		return start;
	}
	else
	{
		while(ptr->data!=val)
		{
			preptr=ptr;
			ptr = ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
		return start;
	}
}
