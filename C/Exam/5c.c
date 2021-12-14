#include<stdio.h>
#include<conio.h>
int main()
{
    int n;
    printf("Enter the number of rows\n");
    scanf("%d",&n);
    int a = (n/2)+1;
    for(int i=a;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        printf("*");
        printf("\n");
    }
    for(int i=2;i<=a;i++)
    {
        for(int j=1;j<=i;j++)
        printf("*");
        printf("\n");
    }
}