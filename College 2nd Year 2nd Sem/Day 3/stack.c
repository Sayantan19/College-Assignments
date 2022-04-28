#include <stdio.h>
#include <stdlib.h>


struct Stack {
    int top;
    int capacity;
    int * data;
};
 
struct Stack * createStack(int );
int isFull(struct Stack * );
int isEmpty(struct Stack * );
void push(struct Stack *, int );
int pop(struct Stack * );
int peek(struct Stack * );
void display(struct Stack * );


/*int main()
{
    struct Stack* stack = createStack(100);
 
    push(stack, 10);
    printf("%d pushed to stack\n", 10);
    push(stack, 20);
    printf("%d pushed to stack\n", 20);
    push(stack, 30);
    printf("%d pushed to stack\n", 30);
 
    printf("%d popped from stack\n", pop(stack));
 	display(stack);
    return 0;
}*/


struct Stack * createStack(int size)
{
    struct Stack * stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = size;
    stack->top = -1;
    stack->data = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}
 
// Stack is full when top is equal to the last index
int isFull(struct Stack * stack)
{
    return stack->top == stack->capacity - 1;
}
 
// Stack is empty when top is equal to -1
int isEmpty(struct Stack * stack)
{
    return stack->top == -1;
}
 
// Function to add an item to stack.  It increases top by 1
void push(struct Stack * stack, int item)
{
    if (isFull(stack))
        return;
    stack->data[++stack->top] = item;

}
 
// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack * stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->data[stack->top--];
}
 
// Function to return the top from stack without removing it
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->data[stack->top];
}
void display(struct Stack * stack)
{
	struct Stack * s;
	int x;
	if (isEmpty(stack))
	{
		printf("Stack is empty");
		return;
	}
	s = createStack(stack->capacity);
	
	printf("\nElements of Stack : ");
	while(!isEmpty(stack))
	{
		x = pop(stack);
		push(s,x);
		printf("%d ",x);
	}
	printf("\n");
	while(!isEmpty(s))
	{
		x = pop(s);
		push(stack,x);
	}
}
 

