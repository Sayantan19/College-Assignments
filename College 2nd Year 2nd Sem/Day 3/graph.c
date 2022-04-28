#include<stdio.h>
#include<stdlib.h>
#include"stack.c"
#include"linear queue.c"

struct Graph
{
	int vertex;
	int edge;
	int ** adjMatrix;
};

struct Graph * createGraph(int v, int e)
{
	int i, j;
	struct Graph * g;
	g = (struct Graph *)malloc(sizeof(struct Graph));

	g->vertex = v;
	g->edge = e;
	g->adjMatrix = (int **)malloc(v * sizeof(int *));

	for(i = 0; i < v; i++)
	{
		g->adjMatrix[i] = (int *)malloc(v * sizeof(int));
		
		for(j = 0; j < v; j++)
			g->adjMatrix[i][j] = 0;
	}
	return g;
}

struct Graph * insertEdge(struct Graph * g, int v1, int v2)
{

	g->adjMatrix[v1][v2] = 1;
	
	g->adjMatrix[v2][v1] = 1;
	
	return g;
}

void printGraph(struct Graph * g)
{
	int i, j;	
	for(i = 0; i < g->vertex; i++)
	{
		for(j = 0; j < g->vertex; j++)
		{
			printf("%d  ", g->adjMatrix[i][j]);
		}
		printf("\n");
	}
}



void DFS(struct Graph * g, int startVertex)
{
	int * visited, i, x;
	struct Stack * stack = createStack(10);
	
	visited = (int *)malloc(g->vertex * sizeof(int));
	
	for(i = 0; i< g->vertex; i++)
		visited[i] = 0;
	
	visited[startVertex] = 1;
	push(stack, startVertex);
	
	printf("\n");
	
	while(!isEmpty(stack))
	{
		x = pop(stack);
		printf("%d->",x);
		for(i = 0;i < g->vertex; i++)
		{
			if(g->adjMatrix[x][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				push(stack, i);
			}
		}			
	}
}
	
void BFS(struct Graph * g, int startVertex)
{
	int * visited, i, x;
	struct Queue * q = create(g->vertex);
	//this array updates the vertices visited
	visited = (int *)malloc(g->vertex * sizeof(int));
	//No elements now. so it is initialized to zero
	for(i = 0; i< g->vertex; i++)
		visited[i] = 0;
	
	visited[startVertex] = 1;
	enqueue(q, startVertex);
	
	printf("\n");
	
	while(!QueueisEmpty(q))
	{
		x = dequeue(q);
		printf("%d->",x);
		for(i = 0;i < g->vertex; i++)
		{
			if(g->adjMatrix[x][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				enqueue(q, i);
			}
		}
	}
	
}
		
int main()
{
    int n, e, v1, v2, i;
	struct Graph * g;
	
	printf("\nEnter the number of node and number of edge : ");
	scanf("%d%d",&n,&e);
    
	g = createGraph(n,e);
    
    printf("Enter the %d Edges",e);
    for(i=0; i<e; i++)
    {
    	printf("\nEnter the source node and destination node: ");
    	scanf("%d%d",&v1, &v2);
    	g = insertEdge(g,v1,v2);
    }

    printGraph(g);
    DFS(g, 0);
    BFS(g,0);


    return 0;
}
