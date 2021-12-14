#include <stdio.h>
#include <stdlib.h>
int trans(int **, int, int);

int main()
{
    int r, c;
    printf("Enter the number of rows in the matrix \n");
    scanf("%d", &r);
    printf("Enter the number of columns in the matrix \n");
    scanf("%d", &c);
    int **arr = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
        arr[i] = (int *)malloc(c * sizeof(int));
    printf("Enter matrix elements:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &arr[i][j]);
    trans(arr, r, c);
    return 0;
}

int trans(int **a, int r, int c)
{
    int t[c][r];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            t[j][i] = a[i][j];
    }
    printf("The transposed matrix is \n");
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
            printf("%d\t", t[i][j]);

        printf("\n");
    }
    return 0;
}
