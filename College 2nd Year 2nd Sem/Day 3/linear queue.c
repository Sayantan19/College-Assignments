#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int front;
	int rear;
	int capacity;
	int * array;
};

struct Queue * create(int);
int QueueisEmpty(struct Queue *);
int QueueisFull(struct Queue *);

void enqueue(struct Queue *,int );
int dequeue(struct Queue *);
//int peek(struct Queue *);

void display1(struct Queue *);


struct Queue * create(int n)
{
	struct Queue * queue = (struct Queue *) malloc (sizeof(struct Queue));
	queue->rear = -1;
	queue->front = -1;
	queue->capacity=n;
	queue->array = (int *) malloc (sizeof(int) * n);
	return queue;
}	

int QueueisEmpty(struct Queue * queue)
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

int QueueisFull(struct Queue * queue)
{
	if(queue->rear == queue->capacity-1)
		return 1;
	else
		return 0;
}

void enqueue(struct Queue * queue,int n)
{
	if(QueueisFull(queue))
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
	if(QueueisEmpty(queue))
	{
		printf("Underflow!\n");
		return -1;
	}
	int x = queue->array[queue->front];
	queue->front++;
	return x;
}

void display1(struct Queue * queue)
{
	struct Queue * q = create(queue->capacity);
	q->rear = queue->rear;
	q->front = queue->front;
	q->capacity = queue->capacity;
	q->array = queue->array;
	if(QueueisEmpty(q))
	{
		//printf("No elements in the queue\n");
		return;
	}	
	printf("%d\n",dequeue(q));
	display1(q);
} 
