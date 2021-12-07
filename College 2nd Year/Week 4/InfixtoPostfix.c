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
void push(struct Stack *,char);
char pop(struct Stack * );
char peek(struct Stack *);
int isOperator(char);
int Precedence(char);
void convert(char *);
void display( struct Stack *);

int main()
{
    char * exp;
    exp = (char *)malloc(sizeof(char)*1000);
    printf("Enter the expression: ");
    scanf("%s",exp);
    int s = strlen(exp);
    char * e1 = (char *)malloc(sizeof(char)*s);
    e1 = exp;
    convert(e1);
}

struct Stack * createStack(int n)
{
    struct Stack *p = (struct Stack *)malloc(sizeof(struct Stack));
    p->capacity=n;
    p->top = -1;
    p->data = (char *)malloc(sizeof(char) * n);
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

void push(struct Stack * s,char d)
{
    if(isFull(s))
    {
        printf("Overflow!!!!\n");
        return;
    }
    s->data[++s->top] = d;
    // printf("Element pushed\n");
}

char pop(struct Stack * s)
{
    if(isEmpty(s))
    {
        printf("Underflow!!!!!\n");
        return 0;
    }
    return s->data[s->top--]; 
}

char peek(struct Stack * s)
{
    if(isEmpty(s))
        return -1;
    return s->data[s->top];
}

int isOperator(char t)
{
    if(t=='+'||t=='-'||t=='*'||t=='/'||t=='%'||t=='^'||t=='('||t==')')
        return 1;
    else
        return 0;
}

int Precedence(char t)
{
    if(t=='^')
        return 3;
    else if(t=='*'||t=='/'||t=='%')
        return 2;
    else if(t=='+'||t=='-')
        return 1;
    else
        return -1;
}
void convert(char * exp)
{
    int i,k;
    struct Stack * post = createStack(strlen(exp));
    char * postfix;
    postfix = (char *)malloc(sizeof(char) * strlen(exp));
    for(i=0,k=-1;i<strlen(exp);i++)    
    {
        char t = exp[i];
        //checks whether t is operand or not
        if(!isOperator(t))
            postfix[++k]=t;
        //if t is '(' then it gets pushed
        else if(t=='(')
            push(post,'(');
        //if t is ')', then pop from stack and output till '(' is encountered        
        else if(t==')')
        {
            while(!isEmpty(post)&&peek(post)!='(')
                postfix[++k] = pop(post);
            if (!isEmpty(post) && peek(post) != '(')
                return ;
            else
                pop(post);
        }
        // if t is an operator
        else 
        {
            while(!isEmpty(post) && Precedence(t) <= Precedence(peek(post)))
                postfix[++k]=pop(post);
            
            push(post,t);
        }
    }
    //pop all elements and copy them to postfix string
    while (!isEmpty(post))
        postfix[++k] = pop(post);
 
    postfix[++k] = '\0';
    printf( "%s\n", postfix);
}
void display(struct Stack * s)
{
    if(isEmpty(s))
        return;
    printf("%c ",peek(s));
    pop(s);
    display(s);
}



