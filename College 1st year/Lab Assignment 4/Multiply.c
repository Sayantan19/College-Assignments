#include <stdio.h>
#include<stdlib.h>
int product(int, int, int **, int, int, int **);
int main()
{
    int m1, m2, n1, n2;
    printf("Enter the number of rows of the first matrix \n");
    scanf("%d", &m1);
    printf("Enter the number of columns of the first matrix \n");
    scanf("%d", &n1);
    int **arr = (int **)malloc(m1 * sizeof(int *));
    for (int i = 0; i < m1; i++)
        arr[i] = (int *)malloc(n1 * sizeof(int));
    printf("Enter the number of rows of the second matrix \n");
    scanf("%d", &m2);
    printf("Enter the number of columns of the second matrix \n");
    scanf("%d", &n2);
    int **arr2 = (int **)malloc(m2 * sizeof(int *));
    for (int i = 0; i < m2; i++)
        arr2[i] = (int *)malloc(n2 * sizeof(int));
    if (n1 != m2)
    {
        printf("Not possible\n");
        return 0;
    }
    printf("Enter the elements of the first matrix \n");
    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n1; j++)
            scanf("%d", &arr[i][j]);
    printf("Enter the elements of the second matrix \n");
    for (int i = 0; i < m2; i++)
        for (int j = 0; j < n2; j++)
            scanf("%d", &arr2[i][j]);
    product(m1, n1, arr, m2, n2, arr2);
    return 0;
}

int product(int m1, int n1, int **a, int m2, int n2, int **b)
{
    
    
        int c[n1][m2];
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                c[i][j] = 0;
                for (int k = 0; k < n1; k++)
                    c[i][j] = c[i][j]+(a[i][k] * b[k][j]);
            }
        }
        printf("The product of the 2 matrices are \n");
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n2; j++)
                printf("%d\t", c[i][j]);
            printf("\n");
        }
    return 0;
}
