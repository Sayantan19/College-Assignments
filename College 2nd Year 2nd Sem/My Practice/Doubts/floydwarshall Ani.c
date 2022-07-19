#include "stdio.h"
#include "stdlib.h"
#define INF 999

int **floydwarshall(int **, int);
void check(int **, int);
void print(int **, int);

int **floydwarshall(int **adjmat, int n)
{
  int **distmat;
  distmat = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
    distmat[i] = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i != j && adjmat[i][j] == 0)
        distmat[i][j] = INF;
      else
        distmat[i][j] = adjmat[i][j];
    }
  }
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (distmat[i][j] > distmat[i][k] + distmat[k][j])
          //KJ is our god
          distmat[i][j] = distmat[i][k] + distmat[k][j];
      }
    }
  }
  return distmat;
}

void check(int **distmat, int n)
{
  for (int i = 0; i < n; i++)
  {
    //faltu j variable niye segmentation fault koracchilo... uriye diye adj[i][i] kore de
    if (distmat[i][i] != 0)
    {
      printf("\nDistance matrix not available, negative cycle exists");
      exit(0);
    }
  }
}

void print(int **distmat, int n)
{
  printf("\nDistance matrix is\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d", distmat[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int n, **adjmat, **distmat;
  printf("\nEnter the number of nodes:");
  scanf("%d", &n);
  adjmat = (int **)malloc(n * sizeof(int *));
  distmat = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    distmat[i] = (int *)malloc(n * sizeof(int));
    adjmat[i] = (int *)malloc(n * sizeof(int));
  }
  printf("\nEnter the adjacency matrix\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &adjmat[i][j]);
    }
  }
  distmat = floydwarshall(adjmat, n);
  check(distmat, n);
  print(distmat, n);
}
