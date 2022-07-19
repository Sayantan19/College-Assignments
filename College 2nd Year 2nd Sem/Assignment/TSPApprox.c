#include<stdio.h>
#include<stdlib.h>
#define INF 9999

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

int ** createGraph(int n)
{
    int ** G;
    G = (int **) malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++)
        G[i] = (int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            G[i][j] = 0;
    return G;
}

int ** addEdge(int ** G, int u,int v)
{
    G[u][v] = 1;
    G[v][u] = 1;
    return G;
}

int ** Prim(int n, int **costMatrix,int * selected)
{
    int **G;
    G = createGraph(n);
    int noofnode = 1,minCost = 0,i,j;
    while(noofnode<n)
    {
        int min=INF,u=-1,v=-1;
        for(i=0;i<n;i++)
        {
            if(selected[i] == 1)
            {
                for(j=0;j<n;j++)
                {
                    if(selected[j]==0 && min>costMatrix[i][j])
                    {
                        min = costMatrix[i][j];
                        u=i;
                        v=j;
                    }       
                }
            }
        }
        if(selected[u] == 1 && selected[v] == 0)
        {
            G = addEdge(G,u,v);
            minCost += min;
            selected[v] = 1;
            noofnode++;
        }
    }
    return G;
}

void DFS(int **G,int n,int startVertex)
{
	int * visited, i, x;
	struct Stack * stack = createStack(10);
	
	visited = (int *)malloc(n * sizeof(int));
	
	for(i = 0; i< n; i++)
		visited[i] = 0;
	
	visited[startVertex] = 1;
	push(stack, startVertex);
	
	printf("\n");
	
	while(!isEmpty(stack))
	{
		x = pop(stack);
		printf("%d->",x);
		for(i = 0;i < n; i++)
		{
			if(G[x][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				push(stack, i);
			}
		}			
	}
    printf("%d",startVertex);
}

int main()
{
    printf("Enter the number of nodes in the graph: ");
    int n;
    scanf("%d",&n);
    int ** adjMat, ** costMat, * selected;
    adjMat = (int **) malloc(sizeof(int *)*n);
    costMat = (int **) malloc(sizeof(int *)*n);
    selected = (int *) malloc (sizeof(int) * n);
    for(int i=0;i<n;i++)
    {
        adjMat[i] = (int *)malloc(sizeof(int )*n);
        costMat[i] = (int *)malloc(sizeof(int )*n);
    }
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adjMat[i][j]);
            if(adjMat[i][j] == 0)
                costMat[i][j] = INF;
            else
                costMat[i][j] = adjMat[i][j];
        }           
    }
    for(int i=0;i<n;i++)
        selected[i] = 0;
    printf("Enter the starting node: ");
    int start;
    scanf("%d",&start);
    selected[start] = 1;
    int ** G = createGraph(n);
    G = Prim (n,costMat,selected);
    printf("The Order of traversal by Approximation Algorithm is: ");
    DFS(G,n,start);
    return 0;
}
