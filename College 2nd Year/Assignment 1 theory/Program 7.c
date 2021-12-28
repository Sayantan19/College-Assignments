#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Stack
{
    int top;
    int *data;
    int capacity;
}stack;

stack * create(int);
int isFull(stack *);
int isEmpty(stack *);

void push(stack *,int);
int pop(stack * );
int peek(stack *);

int check(stack *);

void display(stack *);

int main()
{
    int n;
    printf("Enter the number of elements in the stack: ");
    scanf("%d",&n);
    stack * stack = create(n);
    printf("Enter the stack elements\n");
    for(int i=0;i<n;i++)
    {
        int c;
        scanf("%d",&c);
        push(stack,c);
    }
    if(check(stack)==1)
        printf("The given stack is pairwise consecutive\n");
    else
        printf("The given stack is not pairwise consecutive\n");
    return 0;
}

stack * create(int n)
{
    stack *p = (stack *)malloc(sizeof(stack));
    p->capacity=n;
    p->top = -1;
    p->data = (int *)malloc(sizeof(int) * n);
    return p;
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

void push(stack * s,int d)
{
    if(isFull(s))
    {
        printf("Overflow!!!!\n");
        return;
    }
    s->data[++s->top] = d;
    // printf("Element pushed\n");
}

int pop(stack * s)
{
    if(isEmpty(s))
    {
        printf("Underflow!!!!!\n");
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

void display(stack * s)
{
    struct Stack * s1 = create(s->capacity);
    s1->data = s->data;
    s1->top = s->top;
    if(isEmpty(s1))
    {
        // printf("The stack is empty!\n");
        return;
    }    
    // int x = stack->top;
    printf("%d ",peek(s1));
    pop(s1);
    display(s1);  
}

int check(stack * s)
{
    int i=0,a,b;
    while(!isEmpty(s))
    {
        display(s);
        printf("\n\n");
        if(s->capacity%2==1&&i==0)
        {
            pop(s);
        }
        else if((s->capacity%2==1&&i!=0)||s->capacity%2==0)
        {
            a= peek(s);
            pop(s);
            printf("%d\n\n",a);
            display(s);
            printf("\n\n");
            b = peek(s);
            pop(s);
            printf("\n%d\n\n",b);
            display(s);
            printf("\n\n");
            if(abs(a-b)!=1)
                return 0;
        }
        printf("i=%d\n",i);
        i=i+1;
    }
    return 1;
}