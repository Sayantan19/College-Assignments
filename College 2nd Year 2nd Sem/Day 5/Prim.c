#include<stdio.h>
#include<stdlib.h>
#define INF 9999

void Prim(int n, int **costMatrix,int * selected)
{
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
            printf("%d %d nodes added\n",u,v);
            minCost += min;
            selected[v] = 1;
            noofnode++;
        }
    }
    printf("Minimum Cost of the Spanning tree: %d",minCost);
}

int main()
{
    printf("Enter the number of nodes in the graph");
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
    printf("Enter the starting node");
    int start;
    scanf("%d",&start);
    selected[start] = 1;
    Prim (n,costMat,selected);
    return 0;
}
