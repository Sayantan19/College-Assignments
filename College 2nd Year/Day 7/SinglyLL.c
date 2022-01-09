#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x;
	struct node *next;
};
typedef struct node node;
node *insert_beg(node *);
node *insert_end(node *);
node *insert_before(node *);
node *insert_after(node *);
void display(node *);
node *dlt_beg(node *);
node *dlt_end(node *);
node *dlt_target(node *);
void search(node *);
int count(node *);

node *insert_beg(node *start)
{
	node *ptr;
	int n;
	ptr=(node *)malloc(sizeof(node));
	printf("\n Enter node value=");
	scanf("%d",&n);
	if(start==NULL)
	{
		ptr->x=n;
		start=ptr;
		ptr->next=NULL;
		return start;
	}
	ptr->x=n;
	ptr->next=start;
	start=ptr;
	return start;
}
node *insert_end(node *start)
{
	node *ptr,*fpt=start;
	int n;
	ptr=(node *)malloc(sizeof(node));
	printf("\n Enter node value=");
	scanf("%d",&n);
	if(start==NULL)
	{
		ptr->x=n;
		start=ptr;
		ptr->next=NULL;
		return start; 
	}
	while(fpt->next!=NULL)
	fpt=fpt->next;
	ptr->x=n;
	fpt->next=ptr;
	ptr->next=NULL;
	return start;
}
node *insert_before(node *start)
{
	node *fpt=start,*ptr,*p=start;
	int n,t,flag=0;
	if(start==NULL)
	{
		printf("\n List is Empty. Insertion before a target node is not possible");
		return NULL;
	}
	printf("\n Enter target node value=");
	scanf("%d",&t);
	while(fpt!=NULL)
	{
		if(fpt->x==t)
		{
			printf("\n target node found. Enter node value=");
			scanf("%d",&n);
			flag=1;
			break;
		}
		else
		{
			p=fpt;
		    fpt=fpt->next;
		}
	}
	if(flag==0)
	{
		printf("\n target node not found");
		return start;
	}
	ptr=(node *)malloc(sizeof(node));
	if(p==start)
	{
		ptr->x=n;
		ptr->next=p;
		start=ptr;
		return start; 
	}
	ptr->x=n;
	ptr->next=p->next;
	p->next=ptr;
	return start;
}
node *insert_after(node *start)
{
	node *ptr,*fpt=start,*p;
	int n,t,flag=0;
	if(start==NULL)
	{
		printf("\n List is Empty. Insertion after a target is not possible");
		return NULL;
	}
	printf("\n Enter target node value=");
	scanf("%d",&t);
	while(fpt!=NULL)
	{
		if(fpt->x==t)
		{
			printf("\n target node found. Enter node value=");
			scanf("%d",&n);
			flag=1;
			break;
		}
		else
		fpt=fpt->next;
	}
	if(flag==0)
	{
		printf("\n target node not found");
		return start;
	}
	ptr=(node *)malloc(sizeof(node));
	if(fpt->next==NULL)
	{
		ptr->x=n;
		fpt->next=ptr;
		ptr->next=NULL;
		return start; 
	}
	ptr->x=n;
	ptr->next=fpt->next;
	fpt->next=ptr;
	return start;
}
void display(node *start)
{
	node *ptr=start;
	if(start==NULL)
	{
		printf("\n List is Empty");
		return;
	}
	printf("\n List is :");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->x);
		ptr=ptr->next;
	}
	return ;
}
int count(node *start)
{
	node *ptr=start;
	int c=0;
	while(ptr!=NULL)
	{
		c++;
		ptr=ptr->next;
	}
	return c;
}
void search(node *start)
{
	node *ptr=start;
	int n,flag=0;
	if(start==NULL)
	{
		printf("\n List is empty");
		return;
	}
	printf("\n Enter searching node value=");
	scanf("%d",&n);
	while(ptr!=NULL)
	{
		if(ptr->x==n)
		{
			flag=1;
			break;
		}
		else
		ptr=ptr->next;
	}
	if(flag==1)
	printf("\n %d node is found",n);
	else if(flag==0)
	printf("\n node not found");
	return ;
}
node *dlt_beg(node *start)
{
	if(start==NULL)
	{
		printf("\n List is empty");
		return NULL;
	}
	node *ptr=start;
	start=ptr->next;
	free(ptr);
	printf("\n first node is deleted");
	return start;
}
node *dlt_end(node *start)
{
	node *fpt,*ptr=start;
	if(start==NULL)
	{
		printf("\n List is empty");
		return NULL;
	}
	if(ptr->next==NULL)
	{
		free(ptr);
		return NULL;
	}
	while(ptr->next!=NULL)
	{
		fpt=ptr;
		ptr=ptr->next;
	}
	fpt->next=NULL;
	free(ptr);
	printf("\n last node is deleted");
	return start;
}
node *dlt_target(node *start)
{
	node *fpt=start,*ptr=start;
	int n,flag=0;
	if(start==NULL)
	{
		printf("\n List is empty");
		return NULL;
	}
	printf("\n enter node that you want to delete=");
	scanf("%d",&n);
	while(ptr!=NULL)
	{
		if(ptr->x==n)
		{
			flag=1;
			if(fpt==start)
			start=ptr->next;
			else if(ptr->next==NULL)
			fpt->next=NULL;
			else
			fpt->next=ptr->next;
			free(ptr);
			break;
		}
		fpt=ptr;
		ptr=ptr->next;
	}
	if(flag==0)
	printf("\n target node is not found");
	else if(flag==1)
	printf("\n %d node is deleted",n);
	return start;
}

int main()
{
    int j,n;
    node *start=NULL;
    do 
    {
        printf("\n Press 1  to insert a node");
        printf("\n Press 2  to delete a node");
        printf("\n Press 3  to search for an element");
        printf("\n Press 4  to count the number of nodes");
        printf("\n Press 5  to display the list");
        printf("\n Enter your choice : ");
        scanf("%d", &j);
        switch(j) 
        {
        	case 1:	printf("\n\t1)Insert at beginning\n\t2)Insert at End\n\t3)Insert before a node\n\t4)Insert after a node");
		       	printf("\n Enter your choice : ");
		       	scanf("%d",&j);
		       	switch(j)
		       	{
		       		case 1:	start=insert_beg(start); 
		       				break;
			       	case 2:	start=insert_end(start); 
			       			break;
			       	case 3:	start=insert_before(start); 
			       			break;
			       	case 4:	start=insert_after(start); 
			       			break;
			       	default: printf("\n Invalid option ");
			 }
			  	break;
	    	case 2:	printf("\n\t1)Deletion from start\n\t2)Deletion from End\n\t3)Deletion of a target node");
	           	printf("\n Enter your choice :");
	           	scanf("%d",&j);
	           	switch(j)
	           	{
	           		case 1:	start=dlt_beg(start);
	           				break;
	           	    	case 2:	start=dlt_end(start); 
	           	    			break;
	           	    	case 3:	start=dlt_target(start); 
	           	    			break;
	           	    	default :printf("\n Invalid option ");
			}
				break;
        	case 3:	search(start); 
        			break;
		case 4:	printf("\n Number of node = %d ",count(start)); 
				break;
		case 5:	display(start); 
				break;
        	default:
            		printf("\n\n .......Incorrect Choice........ \n");
        }
    }
    while(j<6);
    return 0;
}