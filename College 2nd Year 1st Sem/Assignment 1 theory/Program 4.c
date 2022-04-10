#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Structure definition for the String
typedef struct Stack
{
    int capacity;
    char * data;
    int top;
}string;

//Basic operations
string * create(int );
int isFull(string *);
int isEmpty(string *);

//Stack operations
void push(string *,char );
char pop(string *);
char peek(string *);

//Operations required for the given problem
void checkPal(char *);
char * reverse(string *);

//Driver function
int main()
{
    char s[100];
    printf("Enter the string: ");
    scanf("%s",s);
    char *str = (char *) malloc( sizeof(char)*strlen(s)); 
    for(int i=0;i<strlen(s);i++)
        str[i] = tolower(s[i]);
    checkPal(str);
}

//Creating memory block for the stack and its elements
string * create(int n)
{
    struct Stack *p = (struct Stack *)malloc(sizeof(struct Stack));
    p->capacity=n;
    p->top = -1;
    p->data = (char *)malloc(sizeof(char) * n);
    return p;
}

//Checks whether stack is full or not
int isFull(string * stack)
{
    if(stack->top == stack->capacity-1)
        return 1;
    else
        return 0;
}

//Checks whether stack is empty or not
int isEmpty(string * s)
{
    if(s->top==-1)
    return 1;
    else
    return 0;
}

//Feeds elementsinto the stack
void push(string * s,char d)
{
    if(isFull(s))
    {
        printf("Overflow!!!!\n");
        return;
    }
    s->data[++s->top] = d;
}

//takes out the last element of the stack(First In Last Out)
char pop(string * s)
{
    if(isEmpty(s))
    {
        printf("Underflow!!!!!\n");
        return 0;
    }
    return s->data[s->top--]; 
}

//returns the last element in the stack
char peek(string * s)
{
    if(isEmpty(s))
        return -1;
    return s->data[s->top];
}

//Reverses the given string from the stack
char * reverse(string * s)
{
    char * str;
    str = (char *)malloc(sizeof(char)*s->capacity);
    for(int i=0;i<s->capacity;i++)
    {
        str[i] =peek(s);        
        pop(s);
    }
    return str;
}

//Checks whether the reversed string is Palindrome or not
void checkPal(char * s)
{
    int n = strlen(s);
    string * stack = create(n);
    for(int i=0;i<n;i++)
        push(stack,s[i]);
    char *s1 = reverse(stack);
    if(!strcmp(s,s1))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
}