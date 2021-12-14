//header files
#include<stdio.h>
#include<stdlib.h>

//function prototypes
int ** create(int,int);
int ** input(int **,int,int);
int ** Search(int **,int,int,int);
void display(int **,int);

//driver function
int main()
{
    int **arr;
    int posr;
    int num,r,c;
    printf("Enter the number of rows of the matrix: ");
    scanf("%d",&r);
    printf("Enter the number of columns of the matrix: ");
    scanf("%d",&c);
    arr = create(r,c);
    printf("Enter the elements of the array\n");
    arr = input(arr,r,c);
    printf("Enter the number you want to search\n");
    scanf("%d",&num);
    int **pos;
    pos = Search(arr,r,c,num);
    display(pos,pos[0][0]);
    return 0;
}

int ** create(int r,int c)
{
    int **a;
    a = (int **)malloc(r * sizeof(int *));
    for(int i=0;i<r;i++)
        a[i] = (int *)malloc(c * sizeof(int));
    return a;
}

int ** input(int **a,int r, int c)
{
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    return a;
}

int ** Search(int **a,int r,int c,int num)
{
    int **pos,r1=1;
    pos = create((r*c),2);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]==num)
            {
                pos[r1][0] = i;
                pos[r1][1] = j;
                r1++;
            }
        }
    }
    pos[0][0] = r1;
    return pos;
}

void display(int **pos,int r)
{
    if(r==0)
    printf("Element not present in the array");
    exit(0);
    for(int i=1;i<r;i++)
    {
        printf("Row: %d\tColumn: %d\n",pos[i][0],pos[i][1]);
        // r++;   
    }
    
}