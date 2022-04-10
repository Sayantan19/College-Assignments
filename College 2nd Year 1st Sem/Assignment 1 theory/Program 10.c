#include<stdio.h>
#include<stdlib.h>

//Structure definition
struct Node
{
    int data;
    struct Node *next;
}*top = NULL; 

//Stack operation prototypes
void push(int);
void pop();
void display();

//driver function
int main()
{
    int j, value;
    do
    {
        printf("\n 1. Push \n 2. Pop \n 3. Display \n 4. Exit");
        printf("\n\n Enter your choice : ");
        scanf("%d",&j);
        switch(j)
        {
            case 1: printf("\n Enter the value to insert : ");
                    scanf("%d", &value);
                    push(value);
                        break;
            
            case 2: pop();
                        break;
            
            case 3: display();
                        break;
            
            case 4: exit(0);
                        break;
            
            default: printf("\n Wrong Choice! \n");
        }
    }
    while(j!=4);
    return 0;
}

//Pushing the value into the stack
void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value; 
    
    if(top == NULL)
        newNode->next = NULL;
    else
        newNode->next = top; 
        top = newNode;
}

//Popping the element from the stack
void pop()
{
    if(top == NULL)
    printf("\n Stack Empty \n");
    else
    {
        struct Node *temp = top;
        printf("\n Popped Element : %d\n", temp->data);
        printf("\n");
        top = temp->next; 
        free(temp);
    }
}

//Displaying stack elements
void display()
{
    if(top == NULL)
    printf("\n Stack Empty \n");
    else
    {
        struct Node *temp = top;
        while(temp->next != NULL)
        {
            printf(" \t%d ",temp->data);
            temp = temp -> next;
        }
        printf(" \t%d ",temp->data);
    }
}
