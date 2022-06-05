#include<stdio.h>
#include<stdlib.h>
#define INF 9999

int nodeUnion(int i,int j,int * parent)
{
    if(i!=j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
    
void edgeSort(int ** edgeList,int e)
{
    int temp;
    for(int i=0;i<e;i++)
    {
        for(int j=0;j<e-i-1;j++)
        {
            if(edgeList[j][2]>edgeList[j+1][2])
            {
                temp = edgeList[j][0];
                edgeList[j][0] = edgeList[j+1][0];
                edgeList[j+1][0] = temp;
                
                temp = edgeList[j][1];
                edgeList[j][1] = edgeList[j+1][1];
                edgeList[j+1][1] = temp;
                
                temp = edgeList[j][2];
                edgeList[j][2] = edgeList[j+1][2];
                edgeList[j+1][2] = temp;
            }
        }
    }
}
   
int NoofEdges(int ** adjMat,int v)
{
    int sum=0;
    for(int i=0;i<v;i++)
    {
        for(int j=i;j<v;j++)
        {
            if(adjMat[i][j]!=0 )
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
        for(int j=i;j<v;j++)
        {
            if(adjMat[i][j]!=0 )
            {
                edgeList[r1][0] = i;
                edgeList[r1][1] = j;
                edgeList[r1][2] = adjMat[i][j];
                r1++;
            }
        }
    }
    edgeSort(edgeList,e);
    return edgeList;
}

int find(int p[],int i)
{
    while(p[i]!=-1)
    {
        i = p[i];
    }
    return i;
}

void Kruskal(int ** edgeList, int e, int v)
{
    int * parent, edgeTrack=1,sum=0;
    parent = (int *) malloc(sizeof(int) *v);
    for(int i=0;i<v;i++)
        parent[i] = -1;
   
    int s,d,x,y,w;
    while(edgeTrack <v)
    {
        for(int i=0;i<e;i++)
        {
            x = edgeList[i][0];
            y = edgeList[i][1];
            w = edgeList[i][2];
            s = find(parent,x);
            d = find(parent,y);
            if(nodeUnion(s,d,parent) == 1)
            {
                printf("Edge (%d %d) cost  %d added\n",x,y,w);
                sum+=w;
				edgeTrack++;              
            }
        }
        
    }
    printf("The weight of the MST is: %d",sum);
}

int main()
{
    printf("Enter the number of nodes of the graph: ");
    int v;
    scanf("%d",&v);
    
    int ** adjMatrix = (int **) malloc(sizeof(int *) * v);
    for(int i=0;i<v;i++)
    {
    	adjMatrix[i] = (int *) malloc(sizeof(int) * v);
    }
    printf("\nEnter the adjacency matrix:\n");
    for(int i=0;i<v;i++)
    {
    	for(int j=0;j<v;j++)
           scanf("%d",&adjMatrix[i][j]);
	}	
           
    int e = NoofEdges(adjMatrix,v);
    printf("%d\n",e);
    int ** edgeList =  ListofEdges(adjMatrix,v,e);
    Kruskal(edgeList,e,v);
    return 0;
    
}


