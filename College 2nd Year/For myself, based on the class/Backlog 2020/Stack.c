#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
    int top;
    int capacity;
    int * data;
}stack;

stack * createStack(int);
int isFull(stack *);
int isEmpty(stack *);
void push(stack *,int);
int pop(stack * );
int peek(stack *);

stack * createStack(int n)
{
    stack * s = (stack *)malloc(sizeof(stack));
    s->capacity = n;
    s->top = -1;
    s-> data = (char *)malloc(sizeof(char)*n);
    return s;
}

int isFull(stack * s)
{
    if(s->top == s->capacity-1)
        return 1;
    else
        return 0;
}

int isEmpty(stack * s)
{
    if(s->top==-1)
        return 1;
    else 
        return 0;
}

void push(stack * s,int n)
{
    if(isFull(s))
    {
        printf("Overflow");
        return;
    }     
    s->data[++s->top]=n;
    // printf("%d pushed in the stack\n",n);
}

int pop(stack * s)
{
    if(isEmpty(s))
    {
        printf("Underflow");
        return 0;
    }
    return s->data[s->top--];
}

int peek(stack * s)
{
    if(isEmpty(s))
        return -1;
    return s->data[s->top];
}
