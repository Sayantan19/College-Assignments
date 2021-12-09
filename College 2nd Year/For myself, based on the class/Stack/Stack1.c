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
    int n,ch,choice,e;
    printf("Enter the number of elements in the stack: ");
    scanf("%d",&n);
    struct Stack * stack = createStack(n);
    do
    {
        printf("1 for push\n2 for pop\n3 for peek\n4 for display\n Enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
            printf("enter the element you want to push: ");
            scanf("%d",&e);
            push(stack,e);
            break;
            case 2:
            printf("You chose to pop an element\n");
            pop(stack);
            break;
            case 3:
            printf("You chose to peek\n");
            peek(stack);
            break;
            case 4:
            printf("The elements of the stack are: ");
            display(stack);
            break;
            default:
            printf("Wrong choice\n");
            break;
        }
        printf("Do you wish to continue?[1/0]: ");
        scanf("%d",&choice);
        if(!choice)
            exit(0);
    }while(1);
    
    return 0;
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
        printf("Overflow\n");
        return;
    }     
    stack->data[++stack->top]=n;
    printf("%d pushed in the stack\n",n);
}

int pop(struct Stack * stack)
{
    if(isEmpty(stack))
    {
        printf("Underflow\n");
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
    struct Stack * s = createStack(stack->capacity);
    s->top = stack->top;
    s->data = stack->data;
    if(isEmpty(stack))
        return;
    // int x = stack->top;
    printf("%d \n",pop(s));
    display(s);  
}