//Use array
 #include<stdio.h>
#include<stdlib.h>
struct Stack{
    int top;
    int capacity;
    int * data;
};

struct Stack * createStack(int);
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
    struct Stack * stack = createStack(n);
    for(int i=0;i<n;i++)
    {
        int c;
        scanf("%d",&c);
        push(stack,c);
    }
    printf("The elements of the stack are: ");
    display(stack);
}
// creating the stack of the given capacity n
struct Stack * createStack(int n)
{
    struct Stack * stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = n;
    stack->top = -1;
    stack-> data = (int *)malloc(sizeof(int)*n);
    return stack;
}

int isFull(struct Stack * stack)
{
    if(stack->top == stack->capacity-1)
        return 1;
    else
        return 0;
}

int isEmpty(struct Stack * stack)
{
    if(stack->top==-1)
        return 1;
    else 
        return 0;
}

void push(struct Stack * stack,int n)
{
    if(isFull(stack))
    {
        printf("Overflow");
        return;
    }     
    stack->data[++stack->top]=n;
    printf("%d pushed in the stack\n",n);
}

int pop(struct Stack * stack)
{
    if(isEmpty(stack))
    {
        printf("Underflow");
        return 0;
    }
    return stack->data[stack->top--];
}

int peek(struct Stack * stack)
{
    if(isEmpty(stack))
        return -1;
    return stack->data[stack->top];
}

void display(struct Stack * stack)
{
    if(isEmpty(stack))
        return;
    int x = stack->top;
    printf("%d ",pop(stack));
    display(stack);  
}