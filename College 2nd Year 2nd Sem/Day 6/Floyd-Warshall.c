#include<stdio.h>
#include<stdlib.h>
#define INF 9999

void floydWarshall(int ** D,int n)
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(D[i][j] > (D[i][k]+D[k][j]))
                    D[i][j] = D[i][k]+D[k][j];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(D[i][i]!=0)
        {
            printf("There exists a negative cycle\n");
            exit(0);
        }    
    }
    
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(D[i][j] == INF)
                printf("INF ");
            else
                printf("%d ",D[i][j]); 
        }
        printf("\n");       
    }                   
}
int main()
{
    printf("Enter the number of nodes in the graph");
    int n;
    scanf("%d",&n);
    int ** adjMat, ** distMat;
    adjMat = (int **) malloc(sizeof(int *)*n);
    distMat = (int **) malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++)
    {
        adjMat[i] = (int *)malloc(sizeof(int )*n);
        distMat[i] = (int *)malloc(sizeof(int )*n);
    }
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adjMat[i][j]);
            if(adjMat[i][j] == 0 && i!=j)
                distMat[i][j] = INF;
            else
                distMat[i][j] = adjMat[i][j];
        }           
    }
    floydWarshall(distMat,n);
    return 0;
}
