#include <stdio.h>
#include<stdlib.h>
int ** create(int,int);
int ** input(int **,int,int);
int ** product(int, int, int **, int, int, int **);
int display(int,int,int **);
int main()
{
    int m1, m2, n1, n2;
    printf("Enter the number of rows of the first matrix \n");
    scanf("%d", &m1);
    printf("Enter the number of columns of the first matrix \n");
    scanf("%d", &n1);
    int **arr;
    arr = create(m1,n1);
    printf("Enter the number of rows of the second matrix \n");
    scanf("%d", &m2);
    printf("Enter the number of columns of the second matrix \n");
    scanf("%d", &n2);
    int **arr2;
    arr2 = create(m2,n2);
    if (n1 != m2)
    {
        printf("Not possible\n");
        return 0;
    }
    printf("Enter the elements of the first matrix \n");
    arr = input(arr,m1,n1); 
    printf("Enter the elements of the second matrix \n");
    arr2 = input(arr2,m2,n2);
    int **pro;
    // pro = create(m1,n2);
    pro = product(m1, n1, arr, m2, n2, arr2);
    printf("The product of the 2 matrices are \n");
    display(m1,n2,pro);
    return 0;
}

int ** create(int r,int c)
{
    int **arr = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
        arr[i] = (int *)malloc(c * sizeof(int));
    return arr;
}

int ** input(int **arr,int r,int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &arr[i][j]);
    return arr;
}

int ** product(int m1, int n1, int **a, int m2, int n2, int **b)
{
    
    
        int **c;
        c = create(m1,n2);
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                c[i][j] = 0;
                for (int k = 0; k < n1; k++)
                    c[i][j] = c[i][j]+(a[i][k] * b[k][j]);
            }
        }
        return c;

}

int display(int r,int c,int **o)
{
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                printf("%d\t", o[i][j]);
            printf("\n");
        }
}