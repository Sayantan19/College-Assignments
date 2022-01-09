#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int front;
	int rear;
	int capacity;
	int * array;
};

typedef struct Stack{
	struct Queue * q1;
	struct Queue * q2;
}stack;

stack * create(int);
int isEmpty(struct Queue *);
int isFull(struct Queue *);

void enqueue(struct Queue *,int );
int dequeue(struct Queue *);
int peek(struct Queue *);

void push(stack *,int );
int pop(stack *);
int peekStack(stack * );

void display(stack *);

int main()
{
	int ch,choice,n,x;
	printf("Enter the capacity of the stack: ");
	scanf("%d",&n);
	stack * stack1 = create(n);
	do
	{
		printf("1 for push\n2 for pop\n3 for peek\n4 for display\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the element you wish to push: ");
				scanf("%d",&x);
				push(stack1,x);
				break;
			case 2:
				printf("Element being popped\n");
				pop(stack1);
				// printf("Element dequeued\n");
				break;
			case 3:
				printf("%d is the front element at present\n",peekStack(stack1));
				break;
			case 4:
				display(stack1);
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

stack * create(int n)
{
	stack * s = (stack *)malloc(sizeof(stack));
	s->q1 = (struct Queue *) malloc (sizeof(struct Queue));
	s->q2 = (struct Queue *) malloc (sizeof(struct Queue));
	s->q1->capacity=n;
	s->q2->capacity=n;
	s->q1->rear = -1;
	s->q2->rear = -1;
	s->q1->front = -1;
	s->q2->front = -1;
	s->q1->array = (int *) malloc (sizeof(int) * n);
	s->q2->array = (int *) malloc (sizeof(int) * n);
	return s;
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

void enqueue(struct Queue * queue,int x)
{
	if(isFull(queue))
	{
		printf("Overflow!\n");
		return;
	}
	if(queue->front==-1&&queue->rear==-1)
	{
		queue->front = 0;
		queue->rear = 0;
	}
	else if(queue->rear == queue->capacity-1 && queue->front!=0)
		queue->rear = 0;
	else
		queue->rear = (queue->rear+1)%queue->capacity;
	queue->array[queue->rear] = x;
}

int dequeue(struct Queue * queue)
{
	if(isEmpty(queue))
	{
		printf("Underflow!\n");
		return -1;
	}
	int x = queue->array[queue->front];
	if(queue->front==queue->rear)
	{
		queue->front=-1;
		queue->rear=-1;
	}
	else if(queue->front==queue->capacity-1)
		queue->front=0;
	else		
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

void push(stack * s,int x)
{
	enqueue(s->q1,x);
}

void reverseQueue(struct Queue * q)
{
	if(isEmpty(q))
		return;
	else
	{
		int data = q->front;
		dequeue(q);
		reverseQueue(q);
		enqueue(q,data);
	}
}
int pop(stack * s)
{
	if(isEmpty(s->q1)&&isEmpty(s->q2))
	{
		printf("Stack empty\n");
		return -1;
	}

	if(isEmpty(s->q2))
	{
		while(!isEmpty(s->q1))
		{
			enqueue(s->q2,peek(s->q1));
			dequeue(s->q1);
		}
		reverseQueue(s->q2);
	}
	return dequeue(s->q2);
}

int peekStack(stack * s)
{
	if(isEmpty(s->q2))
		return s->q1->array[s->q1->rear];
	else
		return s->q2->array[s->q2->rear];
}

void display(stack * s)
{
	stack * s1 = create(s->q1->capacity);
    s1->q1->array = s->q1->array;
    s1->q2->array = s->q2->array;
    s1->q1->front = s->q1->front;
    s1->q2->front = s->q2->front;
    s1->q1->rear = s->q1->rear;
    s1->q2->rear = s->q2->rear;
	s1->q1->array = s->q1->array;
	s1->q2->array = s->q2->array;
	if(isEmpty(s1->q1)&&isEmpty(s1->q2))
	{
		//printf("No elements in the queue\n");
		return;
	}	
	printf("%d\n",peekStack(s1));
	pop(s1);
	display(s1);
} 