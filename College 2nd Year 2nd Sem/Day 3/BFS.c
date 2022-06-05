#include <stdio.h>
#include <stdlib.h>
#include "linear queue.c"

typedef struct Graph
{
    int **adjmatrix;
    int vertex;
    int edge;
} graph;

graph *createGraph(int, int);
graph *insertEdge(graph *, int, int);
void BFSMain(graph *, int *, struct Queue *);
// void BFS(graph *, int);
void printGraph(struct Graph *);

int main()
{
    int n, e, v1, v2, i;
    graph *g;

    printf("\nEnter the number of node and number of edge : ");
    scanf("%d%d", &n, &e);

    g = createGraph(n, e);

    printf("Enter the %d Edges", e);
    for (i = 0; i < e; i++)
    {
        printf("\nEnter the source node and destination node: ");
        scanf("%d%d", &v1, &v2);
        g = insertEdge(g, v1, v2);
    }

    printGraph(g);
    // DFS(g, 0);
    int *visited, v = g->vertex;
    visited = (int *)malloc(sizeof(int) * v);
    for (int i = 0; i < v; i++)
        visited[i] = 0;
    struct Queue *q = create(v);
    if (visited[0] == 0)
    {
        visited[0] = 1;
        enqueue(q, 0);
        BFSMain(g, visited, q);
    }
    return 0;
}

graph *createGraph(int v, int e)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->vertex = v;
    g->edge = e;
    g->adjmatrix = (int **)malloc(sizeof(int *) * v);
    for (int i = 0; i < v; i++)
        g->adjmatrix[i] = (int *)malloc(sizeof(int) * v);
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            g->adjmatrix[i][j] = 0;
    return g;
}

graph *insertEdge(graph *g, int v1, int v2)
{
    g->adjmatrix[v1][v2] = 1;
    return g;
}



void BFSMain(graph *g, int *visited, struct Queue *q)
{
    if (QueueisEmpty(q))
        return;
    int v = g->vertex;
    int x = dequeue(q);
    printf("%d->", x);
    for (int j = 0; j < v; j++)
    {
        if (g->adjmatrix[x][j] == 1 && visited[j] == 0)
        {
            visited[j] = 1;
            enqueue(q, j);
        }
    }
    BFSMain(g, visited, q);
}

void printGraph(struct Graph *g)
{
    int i, j;
    for (i = 0; i < g->vertex; i++)
    {
        for (j = 0; j < g->vertex; j++)
        {
            printf("%d  ", g->adjmatrix[i][j]);
        }
        printf("\n");
    }
}
