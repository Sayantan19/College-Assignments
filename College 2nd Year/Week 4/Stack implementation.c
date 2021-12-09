#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int top;
    int capacity;
    int * data;
};

struct Stack * create(int);
int isFull(struct Stack *);
int isEmpty(struct Stack *);
void push(struct Stack *,int);
int pop(struct Stack * );
int peek(struct Stack *);
void display( struct Stack *);

int main()
{
    int n;
    printf("Enter the number of elements in the stack: ");
    scanf("%d",&n);
    struct Stack * stack = create(n);
    for(int i=0;i<n;i++)
    {
        int c;
        scanf("%d",&c);
        push(stack,c);
    }
    printf("The elements of the stack are: ");
    display(stack);
}

struct Stack * create(int n)
{
    struct Stack *p = (struct Stack *)malloc(sizeof(struct Stack));
    p->capacity=n;
    p->top = -1;
    p->data = (int *)malloc(sizeof(int) * n);
    return p;
}

int isFull(struct Stack * stack)
{
    if(stack->top == stack->capacity-1)
        return 1;
    else
        return 0;
}

int isEmpty(struct Stack * s)
{
    if(s->top==-1)
    return 1;
    else
    return 0;
}

void push(struct Stack * s,int d)
{
    if(isFull(s))
    {
        printf("Overflow!!!!\n");
        return;
    }
    s->data[++s->top] = d;
    printf("Element pushed\n");
}

int pop(struct Stack * s)
{
    if(isEmpty(s))
    {
        printf("Underflow!!!!!\n");
        return 0;
    }
    return s->data[s->top--]; 
}

int peek(struct Stack * s)
{
    if(isEmpty(s))
        return -1;
    return s->data[s->top];
}

void display(struct Stack * s)
{
    struct Stack * s1 = create(s->capacity);
    s1->data = s->data;
    if(isEmpty(s1))
    {
        printf("The stack is empty!\n");
        return;
    }    
    // int x = stack->top;
    printf("%d ",peek(s1));
    pop(s1);
    display(s1);  
}

