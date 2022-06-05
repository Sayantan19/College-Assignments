#include<stdio.h>
#include<stdlib.h>
#define INF 9999

int matrixChain(int p[], int n)
{
    int d,i,k,j,min,m=n+1;
    //We take m = n+1 because the method we are using involves in the matrix starting from 1.
    //If we need to start from 0, a lot of adjustments need to be made. so we avoid it.
    int M[m][m], S[m][m];
    //The M array stores the minimum number of multiplications required for multiplying the matrices
    //The S array stores the value of k for which the corresponding minimum multiplications are found for M matrix
    
    //Setting all the diagonal elements' value to zero
    for(i=1;i<m;i++)
        M[i][i] = 0;
    
    //Row traversal loop
    for(d=1;d<m-1;d++)
    {
        //column traversal loop
        for(i=1;i<m-d;i++)
        {
            j=i+d;
            min=INF;
            //k loop to check the minimum number of multiplications and update the M matrix accordingly
            for(k=i;k<j;k++)
            {
                int x = M[i][k] + M[k+1][j] + p[i-1]*p[k]*p[j];
                if(x<min)
                {
                    min=x;
                    S[i][j] = k;
                }
                M[i][j] = min;
            }
        }
    }    
    //this will return the minimum number of matrix multiplications required to multiply all the matrices
    return M[1][m-1];
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
