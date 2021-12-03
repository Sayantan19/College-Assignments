#include<stdio.h>
void trans(int, int,int[][100]);
int main()
{
    int r,c;
    printf("Enter the number of rows in the matrix: ");
    scanf("%d",&r);
    printf("Etner the number of columns of the matrix: ");
    scanf("%d",&c);
    printf("Enter the matrix elements\n");
    int m[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            scanf("%d",&m[i][j]);
    }
    trans(r,c,m);
    return 0;
}

void trans(int r,int c,int a[r][c])
{
    int t[c][r];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            t[j][i] = a[i][j];
    }
    printf("The transposed matrix is \n");
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
            printf("%d\t",t[i][j]);
        printf("\n");
    }
}
