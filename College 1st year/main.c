/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<math.h>
int main()
{
    int n,x,i,j,fact=1;
    double a,b,c;
    float sum=0;
    printf("\n Enter Value of n and x : ");
    scanf("%d%d",&n,&x);
    for(i=0;i<n;i++)
    {
        a=pow(x,i);
        b=pow(-1,i);
        c+=1/(a*b);
    }
    printf("\n Sum of Series = %lf",c);
    return 0;
}

