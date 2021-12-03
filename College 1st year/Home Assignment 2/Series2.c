#include<stdio.h>
int main()
{
    int n;
    printf("Enter the value of n ");
    scanf("%d",&n);
    float s=0.0;
    for(int i=1;i<=n;i++)
        s = s+(1.0/i);
    printf("%0.2f",s);
    return 0;
}