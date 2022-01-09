#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//defining the stack
typedef struct Stack
{
    int top;
    int *data;
    int capacity;
}stack;

//basic operations
stack * create(int);
int isFull(stack *);
int isEmpty(stack *);

//stack operations
void push(stack *,int);
int pop(stack * );
int peek(stack *);

//prototype for checking whether the elements are pairwise consecutive or not
int check(stack *);

//protoype to display the stack
void display(stack *);

//driver function
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

//creates memory block for the stack and its elements
stack * create(int n)
{
    stack *p = (stack *)malloc(sizeof(stack));
    p->capacity=n;
    p->top = -1;
    p->data = (int *)malloc(sizeof(int) * n);
    return p;
}

//checks whether the stack is full
int isFull(stack * s)
{
    if(s->top == s->capacity-1)
        return 1;
    else
        return 0;
}

//checks whether the stack is empty
int isEmpty(stack * s)
{
    if(s->top==-1)
    return 1;
    else
    return 0;
}

//feeds an element in the stack
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

//removes the last entered element
int pop(stack * s)
{
    if(isEmpty(s))
    {
        printf("Underflow!!!!!\n");
        return 0;
    }
    return s->data[s->top--]; 
}

//returns the last element in the stack
int peek(stack * s)
{
    if(isEmpty(s))
        return -1;
    return s->data[s->top];
}

//displays the stack elements
void display(stack * s)
{
    struct Stack * s1 = create(s->capacity);
    s1->data = s->data;
    s1->top = s->top;
    if(isEmpty(s1))
    {
        return;
    }    
    printf("%d ",peek(s1));
    pop(s1);
    display(s1);  
}

//checks whether the elements of the stack is pairwise consecutive or not
int check(stack * s)
{
    int i=0,a,b;
    while(!isEmpty(s))
    {
        if(s->capacity%2==1&&i==0)
        {
            pop(s);
        }
        else if((s->capacity%2==1&&i!=0)||s->capacity%2==0)
        {
            a= peek(s);
            pop(s);
            b = peek(s);
            pop(s);
            if(abs(a-b)!=1)
                return 0;
        }
        i=i+1;
    }
    return 1;
}