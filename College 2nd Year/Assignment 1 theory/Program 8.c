#include<stdio.h>
#include<stdlib.h>

//Stack definition
typedef struct Node
{
    int top;
    int capacity;
    int * data;
}node;

//Queue definition(2 stacks)
typedef struct Queue
{
    node * n1;
    node * n2;
}queue;

//Creating the memory block for the queue and the member stacks
queue * create(int n)
{
    queue * q = (queue *)malloc(sizeof(queue));
    q->n1 = (node *)malloc(sizeof(node));
    q->n2 = (node *)malloc(sizeof(node));
    q->n1->capacity = n;
    q->n2->capacity = n;
    q->n1->top = -1;
    q->n2->top = -1;
    q->n1->data = (int *)malloc(sizeof(int)*n);
    q->n2->data = (int *)malloc(sizeof(int)*n);
    return q;
}

//checks whether the stack is full
int isFull(node * s)
{
    if(s->top == s->capacity-1)
        return 1;
    else
        return 0;
}

//checks whether the stack is empty
int isEmpty(node * s)
{
    if(s->top==-1)
    return 1;
    else
    return 0;
}

//Pushing element into the stack
void push(node * n,int x)
{
    if(isFull(n))
    {
        printf("Overflow!!!!\n");
        return;
    }
    n->data[++n->top] = x;
    // printf("Element pushed\n");
}

//Popping an element out of the stack
int pop(node * n)
{
    if(isEmpty(n))
    {
        printf("Underflow!!!!!\n");
        return 0;
    }
    return n->data[n->top--]; 
}

//Returns the last element
int peek(node * n)
{
    if(isEmpty(n))
        return -1;
    return n->data[n->top];
}

//Enqueue operation
void enqueue(queue * q,int x)
{
    push(q->n1,x);
}

//Dequeue operation
int dequeue(queue * q)
{
    if(isEmpty(q->n2)&&isEmpty(q->n1))
    {
        printf("Queue Empty\n");
        return -1;
    }

    if(isEmpty(q->n2))
    {
        while(!isEmpty(q->n1))
        {
            push(q->n2,peek(q->n1));
            pop(q->n1);
        }
    }
    return pop(q->n2);
}

//Display function
void display(queue * q)
{
	queue * q1 = create(q->n1->capacity);
    q1->n1->data = q->n1->data;
    q1->n2->data = q->n2->data;
    q1->n1->top = q->n1->top;
    q1->n2->top = q->n2->top;
	if(isEmpty(q1->n1)&&isEmpty(q1->n2))
	{
		//printf("No elements in the queue\n");
		return;
	}	
	printf("%d\n",dequeue(q1));
	display(q1);
} 

//Driver function
int main()
{
	int ch,choice,n,element;
	printf("Enter the capacity of the queue: ");
	scanf("%d",&n);
	queue * q = create(n);
	do
	{
		printf("1 for enqueue\n2 for dequeue\n3 for display\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d",&element);
				enqueue(q,element);
				break;
			case 2:
				printf("Element being dequeued\n");
				dequeue(q);
				printf("Element dequeued\n");
				break;
			case 3:
				display(q);
				break;
			default:
				printf("Wrong Choice!\n");
				break;
		}
		printf("Do you wish to continue[1/0]? ");
		scanf("%d",&ch);
		if(!ch)
			exit(0);
	}while(1);
	return 0;
}