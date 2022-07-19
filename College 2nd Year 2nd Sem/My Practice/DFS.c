#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    int *data;
    int capacity;
} stack;

stack *createStack(int n)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->capacity = n;
    s->data = (int *)malloc(sizeof(int) * n);
    s->top = -1;
    return s;
}

int isEmpty(stack *s)
{
    return s->top == -1;
}

int isFull(stack *s)
{
    return s->top == s->capacity - 1;
}

int pop(stack *s)
{
    if (isEmpty(s))
        return -1;
    return s->data[s->top--];
}

void push(stack *s, int n)
{
    if (isFull(s))
        return;
    s->data[++s->top] = n;
}

int **createAdjMat(int n)
{
    int **adj = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        adj[i] = (int *)malloc(sizeof(int) * n);
    printf("Enter the elements of the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    return adj;
}

void DFS(int **adj, int n, stack *s, int *visited)
{
    if (isEmpty(s))
        return;
    int x = pop(s);
    printf("%d ", x);
    for (int i = 0; i < n; i++)
    {
        if (adj[x][i] == 1)
        {
            if (visited[i] == 0)
            {
                push(s, i);
                visited[i] = 1;
            }
        }
    }
    DFS(adj, n, s, visited);
}

int main()
{
    int n;
    printf("Enter the number of nodes of the graph: ");
    scanf("%d", &n);
    int **adj = createAdjMat(n);
    stack *s = createStack(n);
    int *visited = (int *)malloc(sizeof(int) * n);
    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    if (visited[start] == 0)
    {
        push(s, start);
        visited[start] = 1;
        DFS(adj, n, s, visited);
    }
}