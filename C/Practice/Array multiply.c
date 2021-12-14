#include <stdio.h>
int product(int, int, int[][100], int, int, int[][100]);
int main()
{
    int m1, m2, n1, n2, a[100][100], b[10][100];
    printf("Enter the number of rows of the first matrix \n");
    scanf("%d", &m1);
    printf("Enter the number of columns of the first matrix \n");
    scanf("%d", &n1);
    printf("Enter the elements of the first matrix \n");
    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n1; j++)
            scanf("%d", &a[i][j]);
    printf("Enter the number of rows of the second matrix \n");
    scanf("%d", &m2);
    printf("Enter the number of columns of the second matrix \n");
    scanf("%d", &n2);
    printf("Enter the elements of the second matrix \n");
    for (int i = 0; i < m2; i++)
        for (int j = 0; j < n2; j++)
            scanf("%d", &b[i][j]);
    product(m1, n1, a, m2, n2, b);
    return 0;
}

int product(int m1, int n1, int a[][100], int m2, int n2, int b[][100])
{
    if (n1 != m2
    )
    {
        printf("Not possible\n");
        return 0;
    }
    else
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
    }
    return 0;
}
