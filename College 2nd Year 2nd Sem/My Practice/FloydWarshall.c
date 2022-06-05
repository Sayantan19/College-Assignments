#include<stdio.h>
#include<stdlib.h>
#define INF 9999

void FloydWarshall(int **,int );

int main()
{
    int n,**adj,**d;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d",&n);
    adj = (int **) malloc (sizeof(int *) * n);
    d = (int **) malloc (sizeof(int *) * n);
    for(int i=0;i<n;i++)
    {
        adj[i] = (int *) malloc (sizeof(int )*n);
        d[i] = (int *) malloc (sizeof(int )*n);
    }
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
            if(i!=j && adj[i][j] == 0)
                d[i][j] = INF;
            else
                d[i][j] = adj[i][j];
        }
    FloydWarshall(d,n);
}

//Uses dynamic programming formula to find all pairs' shortest paths
void FloydWarshall(int ** d,int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(d[i][j]>(d[i][k]+d[k][j]))
                    d[i][j] = d[i][k]+d[k][j];
            }
        }
    }
    //checks for negative cycle
    for(int i=0;i<n;i++)
        if(d[i][i]!=0)
        {
            printf("There exists a negative cycle!\n");
            exit(0);
        }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            if(d[i][j] == INF)
                printf("INF ");
            else   
                printf("%d ",d[i][j]);
        printf("\n");
    }
}