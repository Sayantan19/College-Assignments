#include<stdio.h>
#include<stdlib.h>
#define INF 9999

int NoofEdges(int ** adjMat,int v)
{
    int sum=0;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(adjMat[i][j]!=0)
                sum++;
        }
    }
    return sum;
}

int ** ListofEdges(int ** adjMat,int v,int e)
{
    int r1=0;
    int **edgeList = (int **) malloc(sizeof(int*)*e);
    for(int i=0;i<e;i++)
        edgeList[i] = (int *) malloc(sizeof(int) *3);
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(adjMat[i][j]!=0)
            {
                edgeList[r1][0] = i;
                edgeList[r1][1] = j;
                edgeList[r1][2] = adjMat[i][j];
                r1++;
            }
        }
    }
    return edgeList;
}

void BellmanFord(int **edgeList,int v,int e,int start)
{
    
    int dist[v];
    for(int i=0;i<v;i++)
        dist[i] = INF;
    dist[start] = 0;
    for(int i=0;i<v-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            int s = edgeList[j][0];
            int d = edgeList[j][1];
            int w = edgeList[j][2];            
            if((dist[s]+w)<dist[d])
                dist[d] = dist[s]+w;
        }
    }
    for(int j=0;j<e;j++)
    {
        int s = edgeList[j][0];
        int d = edgeList[j][1];
        int w = edgeList[j][2]; 
        if(dist[s]!=INF && ((dist[s]+w)<dist[d]))
        {
            printf("There exists a negative cycle\n");
            exit(0);
        }    
    }
            
    for(int i=0;i<v;i++)
        printf("%d -> %d: %d \n",start, i, dist[i]);    
}
    
int main()
{
    printf("Enter the number of nodes in the graph: ");
    int n;
    scanf("%d",&n);
    int ** adjMat, **edgeList;
    adjMat = (int **) malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++)
    {
        adjMat[i] = (int *)malloc(sizeof(int )*n);
    }
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adjMat[i][j]);
        }           
    }
    printf("Enter the starting node: ");
    int start;
    scanf("%d",&start);
    int e = NoofEdges(adjMat,n);
    printf("%d\n",e);
    edgeList = ListofEdges(adjMat,n,e);
    for(int i=0;i<e;i++)
    {
        for(int j=0;j<3;j++)
            printf("%d ",edgeList[i][j]);
        printf("\n");
    }
    BellmanFord(edgeList,n,e,start);
    return 0;
}
