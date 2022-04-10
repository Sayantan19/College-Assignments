#include<stdio.h>
#include<stdlib.h>

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

//prototype for deleting the middle element of the stack
stack * delMid(stack *);

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
    printf("The stack elements are: ");
    display(stack);
    printf("\nThe reversed elements of the stack are: ");
    display(delMid(stack));
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
        // printf("The stack is empty!\n");
        return;
    }    
    // int x = stack->top;
    printf("%d ",peek(s1));
    pop(s1);
    display(s1);  
}

//deletes the middlemost element in the stack
stack * delMid(stack * s)
{
    int c=1;
    stack * s1;
    s1 = create(s->capacity-1);
    for(int i=0;i<s->capacity;i++)
    {
        if(c!=s->capacity/2+1)
        {
            push(s1,peek(s));
            pop(s);
        }
        else{
            pop(s);
        }
        c++;
    }
    return s1;
}