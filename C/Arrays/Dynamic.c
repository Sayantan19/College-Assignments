#include <stdio.h>
#include <stdlib.h>
int main()
{
    int r = 3, c = 4;
    int **arr = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
        arr[i] = (int *)malloc(c * sizeof(int));
    printf("Enter matrix elements:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &arr[i][j]);
    printf("\nMatrix elements:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }
    return 0;
}