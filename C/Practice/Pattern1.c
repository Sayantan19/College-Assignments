#include<stdio.h>
#include<conio.h>
void main()
{
    int n;
    printf("Enter the number of rows \n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        printf("*");
        printf("\n");
    }
}