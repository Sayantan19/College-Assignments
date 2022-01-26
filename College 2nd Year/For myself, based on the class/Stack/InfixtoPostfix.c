#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int top;
    int capacity;
    char * data;
};

struct Stack * createStack(int);
int isFull(struct Stack *);
int isEmpty(struct Stack *);
void push(struct Stack *,int);
int pop(struct Stack * );
int peek(struct Stack *);
int isOperator(char);
int Precedence(char);
void convert(char *);

int main()
{
    char * exp = (char * )malloc(sizeof(char) * 10000);
    printf("Enter the expression: ");
    scanf("%s",exp);
    char * e1 = (char * )malloc(sizeof(char) * strlen(exp));
    e1 = exp;
    printf("\nPostfix form of this expression is: ");
    convert(e1);
    return 0;
}

struct Stack * createStack(int n)
{
    struct Stack * stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = n;
    stack->top = -1;
    stack-> data = (char *)malloc(sizeof(char)*n);
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
    // printf("%d pushed in the stack\n",n);
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

int isOperator(char c)
{
    if(c=='^'||c=='%'||c=='/'||c=='*'||c=='+'||c=='-'||c=='('||c==')')
        return 1;
    else
        return 0;
}

int Precedence(char c)
{
    if(c=='^')
        return 3;
    else if(c=='%'||c=='/'||c=='*')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return -1;
}

void convert(char * c)
{
    struct Stack * stack = createStack(strlen(c));
    char * postfix = (char *)malloc(sizeof(char)*strlen(c));
    int k,i;
    for(i=0,k=-1;i<strlen(c);i++)
    {
        char t = c[i];
        //checking whether t is operand. if so, directly place in final exp
        if(!isOperator(t))
            postfix[++k] = t;
        //checking whether t is '('. if so, push it into stack
        else if(t=='(')
            push(stack,'(');
        //checking t is ')' or not
        else if(t==')')
        {
            //popping and placing in final exp till '(' or empty stack is encountered
            while(!isEmpty(stack)&&peek(stack)!='(')
                postfix[++k] = pop(stack);
            //checking whether '(' or stack is non empty
            if(!isEmpty(stack)&&peek(stack)!='(')
                return;
            else
                pop(stack);
        }
        //now for other operators
        else
        {
            //pop and place elements in stack unless empty stack is encountered or the precedence of operator
            //in stack is less than the element
            //then push t into the stack
            while(!isEmpty(stack)&&Precedence(t)<=Precedence(peek(stack)))
                postfix[++k] = pop(stack);
            push(stack,t);
        }

    }
        while(!isEmpty(stack))
            postfix[++k] = pop(stack);

        postfix[++k] = '\0';
        printf("%s\n\n",postfix);
}
