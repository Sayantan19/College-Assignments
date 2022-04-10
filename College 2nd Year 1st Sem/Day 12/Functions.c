#include <stdio.h>
#include <stdlib.h>

typedef struct Graph
{
    int vertex;
    int edge;
    int **AdjMatrix;
} graph;

graph *create(int v, int e)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->vertex = v;
    g->edge = e;
    g->AdjMatrix = (int **)malloc(sizeof(int *) * v);
    for (int i = 0; i < v; i++)
        g->AdjMatrix[i] = (int *)malloc(sizeof(int) * v);
    return g;
}

graph *createAdjMatrix(graph *g)
{
    int a, count = 0;
    for (int i = 0; i < g->vertex; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i == j)
            {
                g->AdjMatrix[i][j] = 0;
                continue;
            }
            printf("Please Enter whether the 2 vertices have an edge between them or not[0/1]: ");
            scanf("%d", &a);
            g->AdjMatrix[i][j] = a;
            g->AdjMatrix[j][i] = a;
            count++;
        }
        if (count == g->edge)
            break;
    }
}