#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int front;
	int rear;
	int capacity;
	int * array;
};

struct Queue * create(int);
int isEmpty(struct Queue *);
int isFull(struct Queue *);

void enqueue(struct Queue *);
int dequeue(struct Queue *);
int peek(struct Queue *);

void display(struct Queue *);

int main()
{
	int ch,choice,n;
	printf("Enter the capacity of the queue: ");
	scanf("%d",&n);
	struct Queue * queue = create(n);
	do
	{
		printf("1 for enqueue\n2 for dequeue\n3 for peek\n4 for display\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue(queue);
				break;
			case 2:
				printf("Element being dequeued\n");
				dequeue(queue);
				printf("Element dequeued\n");
				break;
			case 3:
				printf("%d is the front element at present\n",peek(queue));
				break;
			case 4:
				display(queue);
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

struct Queue * create(int n)
{
	struct Queue * queue = (struct Queue *) malloc (sizeof(struct Queue));
	queue->rear = -1;
	queue->front = -1;
	queue->capacity=n;
	queue->array = (int *) malloc (sizeof(int) * n);
	return queue;
}	

int isEmpty(struct Queue * queue)
{
	if(queue->front>queue->rear)
	{
		queue->front=-1;
		queue->rear=-1;
		return 1;
	}
	else if(queue->front<0)
		return 1;	
	else 
		return 0;
}

int isFull(struct Queue * queue)
{
	if(queue->rear == queue->capacity-1)
		return 1;
	else
		return 0;
}

void enqueue(struct Queue * queue)
{
	int n;
	printf("Enter the element you wish to enqueue: ");
	scanf("%d",&n);
	if(isFull(queue))
	{
		printf("Overflow!\n");
		return;
	}
	if(queue->front==-1)
		queue->front=0;
	queue->array[++queue->rear] = n;
}

int dequeue(struct Queue * queue)
{
	if(isEmpty(queue))
	{
		printf("Underflow!\n");
		return -1;
	}
	int x = queue->array[queue->front];
	queue->front++;
	return x;
}

int peek(struct Queue * queue)
{
	if(isEmpty(queue))
	{
		printf("No elements in the queue\n");
		return -1;
	}
	return queue->array[queue->front];
}		
void display(struct Queue * queue)
{
	struct Queue * q = create(queue->capacity);
	q->rear = queue->rear;
	q->front = queue->front;
	q->capacity = queue->capacity;
	q->array = queue->array;
	if(isEmpty(q))
	{
		//printf("No elements in the queue\n");
		return;
	}	
	printf("%d\n",peek(q));
	dequeue(q);
	display(q);
} 
