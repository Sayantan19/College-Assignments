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

int count()
{
	int c;
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        node * p = (node *)malloc(sizeof(node));
        p = head;
        while(p->next!=NULL)
		{
			c++;
            p = p->next; 
		}
    }
	return c;
}

int Search(int indexValue)
{
	int flag=0,c=0;
    if(head==NULL)
    {
        printf("Empty List!");
        return 0;
    } 
    else
    {
        node * p = (node *)malloc(sizeof(node));
        p = head;
        while(p->next!=NULL)
		{
			if(p->data==indexValue)
			{
				flag=1;
				break;
			}
			c++;
            p = p->next;
		}
		if(flag==0)
			printf("Element not found!\n");
		else
			printf("Element found at %d\n",c);
        return flag;
    }
}

void insertBeg(int value)
{
    node * temp = create(value);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}

void insertMidIndex(node * n,int index,int value)
{
    node * temp = create(value);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        node * p = (node *)malloc(sizeof(node));
        p = head;
        for(int i=0;i<index-1;i++)
            p = p->next;
        temp->next = p->next; 
        p->next=temp;
    }
}

void insertMidValue(node * n,int indexValue,int value)
{
    if(!Search(indexValue))
    {
        printf("\nEntered element does not exist\n");
        return;
    }    
    node * temp = create(value);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        node * p = (node *)malloc(sizeof(node));
        p = head;
        while(p->data!=indexValue)
            p = p->next;
        temp->next = p->next; 
        p->next=temp;
    }
}

void insertEnd(node * n,int value)
{
    node * temp = create(value);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        node * p = (node *)malloc(sizeof(node));
        p = head;
        while(p->next!=NULL)
            p = p->next;
        p->next=temp;
    }
}

void delMidIndex(node * n,int index)
{
    if(head==NULL)
        printf("No elements to be deleted\n");
    else
    {
        node * p = (node *)malloc(sizeof(node));
        p = head;
        for(int i=0;i<index-1;i++)
            p = p->next;
        p->next = p->next->next;
    }
}

void delMidValue(node * n,int indexValue)
{
    if(!Search(indexValue))
    {
        printf("\nEntered element does not exist\n");
        return;
    }    
    if(head==NULL)
        printf("No elements to be deleted\n");
    else
    {
        node * p = (node *)malloc(sizeof(node));
        p = head;
        while(p->data!=indexValue)
            p = p->next;
        p->next = p->next->next;
    }
}

void delBeg()
{
    if(head!=NULL)
        head=head->next;
    else
        printf("Underflow\n");
}

void DelEnd()
{
    if(head==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        node * p = (node *)malloc(sizeof(node));
        p = head;
        if(head->next==NULL)
            head = NULL;
        else
        {
            while(p->next->next!=NULL)
                p = p->next;
            p->next = NULL; 
        }

    }
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
        printf("%d\t%p\n",p->data,p->next);
        p = p->next;
    }
}

int main()
{
    int n,x,index,value,indexValue;
	int choice,ch1,ch2,ch3;
	do
	{
		printf("1 for Insertion\n2 for Deletion\n3 for counting\n4 for Searching\n5 for display\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Welcome to Insertion.\n1 for Insertion at the beginning\n2 for Insertion at the End\n3 for Insertion in the intermediate position\nEnter your choice: ");
				scanf("%d",&ch1);
				switch(ch1)
				{
					case 1:
						if(head==NULL)
						{
							printf("Enter the element to be entered: ");
							scanf("%d",&n);
    						head = create(n);
						}
						else
						{
							printf("Enter the element to be entered: ");
        					scanf("%d",&n);
        					insertBeg(n);
						}
						break;
					case 2:
						if(head==NULL)
						{
							printf("Enter the element to be entered: ");
							scanf("%d",&n);
    						head = create(n);
						}
						else
						{
							printf("Enter the element to be entered: ");
    						scanf("%d",&n);
    						insertEnd(head,n);
						}
						break;
					case 3:
						printf("1 for entering at index\n2 for entering after a particular element\nEnter your choice: ");
						scanf("%d",&ch2);
						switch(ch2)
						{
							case 1:
								printf("\nEnter the index you want to insert the element at: ");
    							scanf("%d",&index);
    							printf("Enter the value you want to insert: ");
    							scanf("%d",&value);
    							insertMidIndex(head,index,value);
								break;
							case 2:
								printf("\nEnter the value after which you want to insert the element at: ");
    							scanf("%d",&indexValue);
    							printf("Enter the value you want to insert: ");
    							scanf("%d",&value);
    							insertMidValue(head,indexValue,value);
								break;
						}
				}
				break;
			case 2:
				printf("Welcome to Deletion.\n1 for Deletion at the beginning\n2 for Deletion at the End\n3 for Deletion in the intermediate position\nEnter your choice: ");
				scanf("%d",&ch1);
				switch(ch1)
				{
					case 1:
						delBeg();
						break;
					case 2:
						DelEnd();
						break;
					case 3:
						printf("1 for entering at index\n2 for entering after a particular element\nEnter your choice: ");
						scanf("%d",&ch2);
						switch(ch2)
						{
							case 1:
								printf("\nEnter the index you want to delete the element from: ");
    							scanf("%d",&index);
    							delMidIndex(head,index); 
								break;
							case 2:
    							printf("\nEnter the value after which you want to delete the element from: ");
    							scanf("%d",&indexValue);
    							delMidValue(head,indexValue);
								break;
						}
				}
				break;
			case 3:
				printf("The number of elements in the Linked list are: %d",count());
				break;
			case 4:
				printf("Enter the value you want to search: ");
				scanf("%d",&indexValue);
				Search(indexValue);
				break;
			case 5:
		    	printf("The element can be displayed as\n");
    			display(head);
				break;
			default:
				printf("Wrong Choice!");
		}
		printf("Do you wish to continue?[1/0]\n");
		scanf("%d",&ch3);
		if(ch3==0)
			exit(0);
	}while(1);
    return 0;
}