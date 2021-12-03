#include<stdio.h>
int main()
{
    int a=0,b=1,n;
    printf("Enter the number of fibonacci digits you want to print \n");
    scanf("%d",&n);
    printf("%d %d ",a,b);
    for(int i=3;i<=n;i++)
    {
        int c = a+b;
        a = b;
        b = c;
        printf("%d ",c);
    }
    return 0;
}