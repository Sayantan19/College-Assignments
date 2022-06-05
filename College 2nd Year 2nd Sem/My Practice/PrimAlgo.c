#include <stdio.h>
#include <stdlib.h>
#define INF 9999

int **createCostMat(int);
void Prim(int **, int, int);
int main()
{
    int n;
    printf("Enter the number of nodes of the graph: ");
    scanf("%d",&n);
    int **cost;
    printf("Enter the adjacency matrix:\n");
    cost = createCostMat(n);
    printf("Enter the starting node: ");
    int start;
    scanf("%d",&start);
    Prim(cost,n,start);
}

int **createCostMat(int n)
{
    int **adj = (int **)malloc(sizeof(int *) * n);
    int **cost = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        adj[i] = (int *)malloc(sizeof(int) * n);
        cost[i] = (int *)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = adj[i][j];
        }
    return cost;
}

void Prim(int **cost, int n, int start)
{
    int *selected;
    selected = (int *)malloc(sizeof(int )*n);
    for(int i=0;i<n;i++)
        selected[i] = 0;
    int noofedges = 1, min,mincost=0;
    selected[start] = 1;
    while (noofedges < n)
    {
        min = INF;
        int u=-1,v=-1;
        for (int i = 0; i < n; i++)
        {
            if (selected[i] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if(selected[j] == 0 && cost[i][j] < min)
                    {
                        u=i;
                        v=j;
                        min = cost[i][j];
                    }
                }
            }
        }
        if(selected[u]==1 && selected[v]==0)
        {
            mincost += min;
            selected[v] = 1;
            printf("\n%d %d added!",u,v);
            noofedges++;
        }
    }
    printf("\nThe minimum cost is %d",mincost);
}