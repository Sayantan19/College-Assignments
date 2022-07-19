#include <stdio.h>
#include <stdlib.h>
#define INF 9999

//return type not specified. 
void PrimsMST(int n, int **costMatrix, int *selected)
{
	// minCost should be initialized here. not in the loop.
	// otherwise the value will be re-initialized everytime
	int i, j, u, v, Nonodes, min, minCost = 0;
	Nonodes = 1;
	while (Nonodes < n)
	{
		u = v = -1;
		min = INF;
		for (i = 0; i < n; i++)
		{
			if (selected[i] == 1)
			{
				for (j = 0; j < n; j++)
				{
					if (selected[j] == 0 && min > costMatrix[i][j])
					{
						min = costMatrix[i][j];
						u = i;
						v = j;
					}
				}
			}
		}
		//this should be inside the while loop. otherwise:
		//1. noofedges will never be updated
		//2. minCost can never be calculated
		//3.selected array can never be updated
		if (selected[u] == 1 && selected[v] == 0)
		{
			printf("\n %d %d is added", u, v);
			minCost += min;
			Nonodes++;
			selected[v] = 1;
		}
	}
	printf("\nMinimum cost is: %d",minCost);
}

int main()
{
	int i, j, n, sn, *selected, **adjMatrix, **costMatrix;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	adjMatrix = (int **)malloc(sizeof(int *) * n);
	costMatrix = (int **)malloc(sizeof(int *) * n);
	selected = (int *)malloc(sizeof(int *) * n);

	for (i = 0; i < n; i++)
	{
		adjMatrix[i] = (int *)malloc(sizeof(int *) * n);
		costMatrix[i] = (int *)malloc(sizeof(int *) * n);
	}
	printf("\nEnter the adjacency matrix: \n");

	for (i = 0; i < n; i++)
	{
		selected[i] = 0;

		for (j = 0; j < n; j++)
		{
			scanf("%d", &adjMatrix[i][j]);
			if (adjMatrix[i][j] == 0)
				//typo here.... == poregechilo
				costMatrix[i][j] = INF;
			else
				//this statement has to be under else block.
				// if adjMatrix[i][j] is not 0, then this will occur
				costMatrix[i][j] = adjMatrix[i][j];
		}
	}
	printf("\nEnter the starting node :");
	scanf("%d", &sn);
	selected[sn] = 1;
	
	PrimsMST(n, costMatrix, selected);
	return 0;
}
