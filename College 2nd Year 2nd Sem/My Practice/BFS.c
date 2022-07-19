#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int front;
    int rear;
    int capacity;
    int *data;
} queue;

// Queue operations
queue *createQueue(int);
int isEmpty(queue *);
int isFull(queue *);
void enqueue(queue *, int n);
int dequeue(queue *);

void display1(queue *);

int **createAdjMat(int);
void BFS(int **, int, int *, queue *);

int main()
{
    int n, start;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);
    int visited[n];
    queue *q = createQueue(n);
    int **adj = createAdjMat(n);
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    printf("Enter the starting node: ");
    scanf("%d", &start);
    if (visited[start] == 0)
    {
        visited[start] = 1;
        enqueue(q, start);
        BFS(adj, n, visited, q);
    }
}

queue *createQueue(int n)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->capacity = n;
    q->front = q->rear = -1;
    q->data = (int *)malloc(sizeof(int) * n);
    return q;
}

int isEmpty(queue *q)
{
    if (q->front > q->rear)
    {
        q->front = -1;
        q->rear = -1;
        return 1;
    }
    else if (q->front < 0)
        return 1;
    else
        return 0;
}

int isFull(queue *q)
{
    if (q->rear == q->capacity - 1)
        return 1;
    else
        return 0;
}

void enqueue(queue *q, int n)
{
    if (isFull(q) == 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->data[++q->rear] = n;
}

int dequeue(queue *q)
{
    if (isEmpty(q) == 1)
        return -1;
    int x = q->data[q->front];
    q->front++;
    return x;
}

int **createAdjMat(int n)
{
    int **adj = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        adj[i] = (int *)malloc(sizeof(int) * n);
    printf("Enter the elements of the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    return adj;
}

void BFS(int **adj, int n, int *visited, queue *q)
{
    if (isEmpty(q))
    {
        // printf("Empty");
        return;
    }
    int x = dequeue(q);
    printf("%d ", x);

    for (int j = 0; j < n; j++)
    {
        if (adj[x][j] == 1)
        {
            if (visited[j] == 0)
            {
                enqueue(q, j);
                visited[j] = 1;
            }
        }
    }
    BFS(adj, n, visited, q);
}

void display1(queue *q1)
{
    queue *q = createQueue(q1->capacity);
    q->rear = q1->rear;
    q->front = q1->front;
    q->capacity = q1->capacity;
    q->data = q1->data;
    if (isEmpty(q))
    {
        // printf("No elements in the queue\n");
        return;
    }
    printf("%d\n", dequeue(q));
    display1(q);
}
