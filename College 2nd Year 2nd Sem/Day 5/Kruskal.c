#include <stdio.h>
#include <stdlib.h>
#define INF 9999

void display(int **edgeList, int e)
{
    for (int i = 0; i < e; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d\t", edgeList[i][j]);
        printf("\n");
    }
}

int NoOfEdges(int **adjMatrix, int v)
{
    int sum = 0;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (adjMatrix[i][j] != 0 && adjMatrix[j][i]!=adjMatrix[i][j])
                sum++;
            else if (adjMatrix[i][j] != 0 && i<j)
                sum++;
        }
    }
    return sum;
}

int **BubbleSort(int **edgeList, int e)
{
    int temp;
    for (int i = 0; i < e; i++)
    {
        for (int j = i + 1; j < e; j++)
        {
            if (edgeList[i][2] > edgeList[j][2])
            {
                temp = edgeList[i][2];
                edgeList[i][2] = edgeList[j][2];
                edgeList[j][2] = temp;

                temp = edgeList[i][1];
                edgeList[i][1] = edgeList[j][1];
                edgeList[j][1] = temp;

                temp = edgeList[i][0];
                edgeList[i][0] = edgeList[j][0];
                edgeList[j][0] = temp;
            }
        }
    }
    return edgeList;
}

int **ListofEdges(int **adjMatrix, int e, int v)
{
    int r1 = 0, c1 = 0;
    int **edgeList = (int **)malloc(sizeof(int *) * e);
    for (int i = 0; i < e; i++)
        edgeList[i] = (int *)malloc(sizeof(int) * 3);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (adjMatrix[i][j] != 0 && (adjMatrix[j][i]!=adjMatrix[i][j] ||  i<j))
            {
                edgeList[r1][c1++] = i;
                edgeList[r1][c1++] = j;
                edgeList[r1][c1] = adjMatrix[i][j];
                c1 = 0;
                r1++;
            }
        }
    }

    BubbleSort(edgeList, e);
    return edgeList;
}

void Kruskal(int **edgeList, int e, int v)
{
    int *visited, edgeTrack = 0, sum=0;
    visited = (int *)malloc(sizeof(int) * v);
    for (int i = 0; i < v; i++)
        visited[i] = 0;
    visited[edgeList[0][0]] = 1;
    while (edgeTrack != (v - 1))
    {
        for (int i = 0; i < e; i++)
        {
            if (visited[edgeList[i][0]] == 1 && visited[edgeList[i][1]] == 0)
            {
                printf("%d %d added!\n",edgeList[i][0],edgeList[i][1]);
                visited[edgeList[i][1]] = 1;
                sum += edgeList[i][2];
            }
        }
        edgeTrack++;
    }
    printf("The weight of the MST is: %d",sum);
}
int main()
{
    printf("Enter the number of nodes of the graph: ");
    int v;
    scanf("%d", &v);

    int **adjMatrix = (int **)malloc(sizeof(int *) * v);
    for (int i = 0; i < v; i++)
        adjMatrix[i] = (int *)malloc(sizeof(int) * v);

    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            scanf("%d", &adjMatrix[i][j]);
    }
    int e = NoOfEdges(adjMatrix, v);
    // printf("%d\n", e);
    // printf("List of edges with their weights are: \n");
    int **edgeList = ListofEdges(adjMatrix, e, v);
    // display(edgeList,e);
    Kruskal(edgeList,e,v);
    return 0;
}