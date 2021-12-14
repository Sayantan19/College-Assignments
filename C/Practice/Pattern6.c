#include<stdio.h>
#include<conio.h>
int main()
{
    int n=4, s=2*n-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        printf(" ");

        for(int j=1;j<=s;j++)
        printf("*");
        s = s-2;
        printf("\n");
    }
}