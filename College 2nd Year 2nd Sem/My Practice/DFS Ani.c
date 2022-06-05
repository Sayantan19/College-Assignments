#include "stdio.h"
#include "stdlib.h"
#define SIZE 50

struct stack
{
  int r, size;
  int *ar;
};

int isEmpty(struct stack *s)
{
  if (s->r == -1)
    return 1;
  return 0;
}

int isFull(struct stack *s)
{
  if (s->r == s->size - 1)
    return 1;
  return 0;
}

void push(struct stack *s, int val)
{
  //error 2. did not check is full condition
  if(isFull(s))
    return;
  s->ar[++s->r] = val;
}

int pop(struct stack *s)
{
  //error 3/ did not check isempty conditon
  int val;
  if(isEmpty(s))
    return -1;
  val = s->ar[s->r--];
  return val;
}

struct graph
{
  int vertices, edges;
  int **adjmat;
};

struct graph *create(int e, int v)
{
  struct graph *g;
  g = (struct graph *)malloc(sizeof(struct graph));
  g->edges = e;
  g->vertices = v;
  g->adjmat = (int **)malloc(v * sizeof(int *));
  for (int i = 0; i < v; i++)
  {
    g->adjmat[i] = (int *)malloc(v * sizeof(int));
    for (int j = 0; j < v; j++)
      g->adjmat[i][j] = 0;
  }
  return g;
}

struct graph *insert(struct graph *g, int v1, int v2)
{
  g->adjmat[v1][v2] = 1;
  g->adjmat[v2][v1] = 1;
  return g;
}

void display(struct graph *g)
{
  for (int i = 0; i < g->vertices; i++)
  {
    for (int j = 0; j < g->vertices; j++)
      printf("%d", g->adjmat[i][j]);
    printf("\n");
  }
}

void recursiveDFS(struct graph *g, struct stack *s, int *visited)
{
  int x, i;
  if (isEmpty(s))
    return;
  x = pop(s);
  printf("%d->", x);
  for (i = 0; i < g->vertices; i++)
  {
    if (g->adjmat[x][i] == 1)
    {
      if (visited[i] == 0)
      {
        visited[i] = 1;
        push(s, i);
      }
    }
  }
  recursiveDFS(g, s, visited);
}
int main()
{
  // stack initializing
  struct stack *s;
  s = (struct stack *)malloc(sizeof(struct stack));
  //Error 1: initialize with -1 because it is an empty matrix
  s->r = -1;
  s->size = SIZE;
  s->ar = (int *)malloc(s->size * sizeof(int));

  // DFS implementation
  struct graph *g;
  int e, v, v1, v2, *visited;
  printf("\nEnter the number of edges and vertices:");
  scanf("%d %d", &e, &v);
  g = create(e, v);

  printf("\nEnter the vertices");
  for (int i = 0; i < e; i++)
  {
    printf("\nEnter the source node and the destination node:");
    scanf("%d %d", &v1, &v2);
    g = insert(g, v1, v2);
  }
  printf("\nAdjacency matrix is:");
  display(g);
  visited = (int *)malloc(v * sizeof(int));
  for (int i = 0; i < v; i++)
    visited[i] = 0;

  int node;
  printf("\nEnter the node from where you want to start:");
  scanf("%d", &node);
  if (visited[node] == 0)
  {
    visited[node] = 1;
    push(s, node);
    recursiveDFS(g, s, visited);
  }
  return 0;
}
