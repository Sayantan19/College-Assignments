#include <stdio.h>
#include <stdlib.h>
#define INF 9999

int NoofEdges(int **, int);
int **ListofEdges(int **, int, int);
void BellmanFord(int **, int, int, int);

int main()
{
    int n, e,start;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);
    int **adj;
    adj = (int **) malloc(sizeof(int *) * n);
    for(int i=0;i<n;i++)
        adj[i] = (int *)malloc(sizeof(int) * n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    e = NoofEdges(adj, n);
    int **edgeList;
    edgeList = ListofEdges(adj,n,e);
    printf("Enter the star node: ");
    scanf("%d",&start);
    BellmanFord(edgeList,n,e,start);
}

void BellmanFord(int **edgeList, int v, int e, int start)
{
    int dist[v], s, d, w;
    for (int i = 0; i < v; i++)
        dist[i] = INF;
    // We initialize the starting element with 0 value
    dist[start] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            s = edgeList[j][0];
            d = edgeList[j][1];
            w = edgeList[j][2];
            if (dist[d] > (dist[s] + w))
                dist[d] = dist[s] + w;
        }
    }

    for (int i = 0; i < v - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            s = edgeList[j][0];
            d = edgeList[j][1];
            w = edgeList[j][2];
            if (dist[d] > (dist[s] + w))
            {
                printf("There exists a negative cycle");
                exit(0);
            }
        }
    }
    for(int i=0;i<v;i++)
        printf("%d ",dist[i]);
}

int NoofEdges(int **adj, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(adj[i][j]!=0)
                sum++;
        }
    }
    return sum;
}

int ** ListofEdges(int **adj,int n,int e)
{
    int **edgeList;
    edgeList = (int **)malloc(sizeof(int *)*e);
    for(int i=0;i<e;i++)
        edgeList[i] = (int *)malloc(sizeof(int )* 3);
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(adj[i][j]!=0)
            {
                edgeList[c][0] = i;
                edgeList[c][1] = j;
                edgeList[c][2] = adj[i][j];
                c++;
            }
        }
    }
    return edgeList;
}