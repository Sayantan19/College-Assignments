#include<stdio.h>
#include<stdlib.h>
int ** create(int,int);
int ** input(int **,int,int);
int ** represent(int **,int ,int);
int nonzero(int **,int,int);
int ** transpose(int **,int);
int ** sort(int **,int **);
void display(int,int,int **);

//Driver function
int main()
{
    int r,c;
    printf("Enter the number of rows\n");
    scanf("%d",&r);
    printf("Enter the number of columns\n");
    scanf("%d",&c);
    int **arr;
    arr = create(r,c);
    printf("Enter the matrix elements \n");
    arr = input(arr,r,c);
    int **rep;
    rep = represent(arr,r,c);
    // int r1 = nonzero(arr,r,c);
    display((rep[0][2]+1),3,rep);
    printf("\n");
    printf("\n");
    int **trans;
    trans = create(nonzero(arr,r,c)+1,3);
    // trans = transpose(rep,(rep[0][2]+1));
    // display((rep[0][2]+1),3,trans);
    // printf("\n");
    // printf("\n");
    trans = sort(trans,rep);
    display((rep[0][2]+1),3,trans);
}

//Creatng the array
int ** create(int r,int c)
{
    int **arr = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
        arr[i] = (int *)malloc(c * sizeof(int));
    return arr;
}

//Input the elements of the array
int ** input(int **arr,int r,int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &arr[i][j]);
    return arr;
}

//Representing The sparse matrix in its array representation
int ** represent(int **a,int r,int c)
{
    int z=nonzero(a,r,c);
    int **re;
    re = create((z+1),3);
    int k=1;
    re[0][0] = r;
    re[0][1] = c;
    re[0][2] = z;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                re[k][0] = i;
                re[k][1] = j;
                re[k][2] = a[i][j];
                k++;
            }
        }
    }
    return re;
}

//calculating the number of non zero elements
int nonzero(int **a,int r,int c)
{
    int z=0; 
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(a[i][j]!=0)
                z++;
    return z;
}

//transposiing without sorting
int ** transpose(int **a,int r)
{
    int temp;
    for(int i=0;i<r;i++)
    {
        temp = a[i][0];
        a[i][0] = a[i][1];
        a[i][1] = temp;
    }
    return a;
}

//Sorting the transposed matrix
int ** sort(int **a,int ** b)
{
    a[0][0] = b[0][1];
    a[0][1] = b[0][0];
    a[0][2] = b[0][2];

    int k = 1;
    int n = b[0][2];
    for(int i=0;i<b[0][1];i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==b[j][1])
            {
                a[k][0] = i;
                a[k][1] = b[j][0];
                a[k][2] = b[j][2];
                k++;
            }
        }
    }
    return a;
}

//Printing the resultant matrix
void display(int r,int c,int **o)
{
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                printf("%d\t", o[i][j]);
            printf("\n");
        }
}
