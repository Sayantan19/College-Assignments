#include<stdio.h>
int prime(int n,int i);

int main()
{
    int n;
printf("Enter a number ");
    scanf("%d",&n);
    prime(n,2);
    return 0;
}

int prime(int n,int i)
{
    int f;
    if(i<=n)
    {
        if(n%i==0)
        {
            printf("%d ",i);
            n/=i;
        }
        else
        i++;
        prime(n,i);
    }
    return 0;
}