#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Stack definition for the Brackets
typedef struct Stack
{
    int capacity;
    char * data;
    int top;
}braces;

//Basic operations
braces * create(int );
int isFull(braces *);
int isEmpty(braces *);

//Stack operations
void push(braces *,char );
char pop(braces *);
char peek(braces *);

//Operations required for the given problem
int isBracket(char);
void checkBalance(char *);

//Driver function
int main()
{
    char exp[100];
    printf("Enter the expression: ");
    scanf("%s",exp);
    checkBalance(exp);
    return 0;
}

//Creates memory block for the stack and its elements
braces * create(int n)
{
    braces * b = (braces *)malloc(sizeof(braces));
    b->top = -1;
    b->capacity = n;
    b->data = (char *)malloc(sizeof(char)*n);
    return b;
}

//Checks whether stack is full or not
int isFull(braces * b)
{
    if(b->top==b->capacity-1)
        return 1;
    else 
        return 0;
}

//Checks whether stack is empty or not
int isEmpty(braces * b)
{
    if(b->top==-1)
        return 1;
    else
        return 0;
}

//Feeds elementsinto the stack
void push(braces * b,char c)
{
    if(isFull(b))
    {
        printf("Overflow!\n");
        return;
    }    
    b->data[++b->top] = c;
}

//takes out the last element of the stack(First In Last Out)
char pop(braces * b)
{
    if(isEmpty(b))
    {
        printf("Underflow!\n");
        return 0;
    }    
    return b->data[--b->top];
}

//returns the last element in the stack
char peek(braces * s)
{
    if(isEmpty(s))
        return -1;
    return s->data[s->top];
}

//Checks whter given character is a Bracket or not
int isBracket(char c)
{
    if(c=='('||c=='{'||c=='[')
        return 1;
    else if(c==')'||c=='}'||c==']')
        return -1;
}

//Checking whether the given expression is balanced in terms of brackets
void checkBalance(char * exp)
{
    int ob1,cb1;
    int len;
    len = strlen(exp);
    braces * ob, * cb;
    char x;
    ob = create(len);
    cb = create(len);
    for(int i=0;i<len;i++)
    {
        if(isBracket(exp[i])==1)
            push(ob,exp[i]);
        else if(isBracket(exp[i])==-1)
            push(cb,exp[i]);
    }
    while(!isEmpty(ob))
    {
        x = pop(ob);
        ob1++;
    } 
    while(!isEmpty(cb))
    {
        x = pop(cb);
        cb1++;
    }  
    if(ob1==cb1)
        printf("%s is a balanced expression\n",exp);
    else  
        printf("%s is not a balanced expression\n",exp);
}