#include <stdio.h>
int UpperTriangular(int n,int a[n][n])
{
	int flag = 0;
    int i, j;
    for (i = 1; i < n; i++)
	{
    	for (j = 0; j < i; j++)
		{
        	if (a[i][j] != 0)
				flag = 0;
			else
				flag = 1;
        }
    }
	return flag;
}

int LowerTriangular(int n,int a[n][n])
{
    int flag =0;
    int i, j;
	for (i = 0; i < n; i++)
	{
    	for (j = i+1; j < n; j++)
		{
        	if (a[i][j] != 0)
				return 0;
        }
    }
    return 1;
}
int main()
{
	int n;
    printf("Enter the dimensions of the matrix: ");
	scanf("%d",&n);
	int mat[n][n];
    int i, j;
    printf("Enter the matrix elements\n");
	for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			scanf("%d",&mat[i][j]);
		}
    if(UpperTriangular(n,mat)==1)
        printf("Upper triangular matrix\n");
    else if(LowerTriangular(n,mat)==1)
        printf("Lower triangular matrix\n");
    else
        printf("Neither\n");
    return 0;
}
