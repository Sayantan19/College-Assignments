#include <stdio.h>
#include <stdlib.h>
#define INF 9999

int *matChain(int *p, int n)
{
    int min, m = n + 1;
    int M[m][m], S[m][m];
    for (int i = 0; i < n; i++)
        M[i][i] = 0;
    for (int d = 0; d < m - 1; d++)
    {
        for (int i = 0; i < m - d; i++)
        {
            int j = d + i;
            min = INF;
            for(int k=i;k<j;k++)
            {
                int x = M[i][k] + M[k+1][j] + p[i-1]*p[k]*p[j];
                if(x<min)
                {
                    min = x;
                    S[i][j] = k;
                }
                M[i][j] = min;
            }
        }
    }
    return M[0][m-1];
}

int main()
{
    int n;
    printf("Enter the number of matrices to be multiplied: ");
    scanf("%d",&n);
    int p[n+1],c=0;
    printf("Define the distinct dimensions of the matrices: \n");
    for(int i=0;i<n+1;i++)
        scanf("%d",&p[i]);
    printf("The minimum number of scalar multiplications needed for this chain of matrices is: %d\n",matrixChain(p,n));
    return 0;
}