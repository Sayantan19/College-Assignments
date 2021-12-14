#include<stdio.h>
int sum(int,int,int[][100]);

int main()
{
    int m,n,a[100][100];
    printf("enter the number of rows in the matrix \n");
    scanf("%d",&m);
    printf("Enter the number of columns of the matrix \n");
    scanf("%d",&n);
    printf("Enter the matrix elements \n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("The sum of the elements of the matrix is %d\n",sum(m,n,a));
    return 0;
}

int sum(int m,int n,int a[][100])
{
    int s=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            s=s+a[i][j];
        }
    }
    return s;
}