#include<stdio.h>
#include<math.h>
int factorial(int n)
{
    int f=1;
    for(int i=1;i<=n;i++)
        f*=i;
    return f;
}

int main()
{
    int x,n;
    printf("Enter the value of x ");
    scanf("%d",&x);
    printf("Enter the value of n ");
    scanf("%d",&n);
    float s = 0.0,k=1.0,c=0.0;
    for(int i=1;i<=n;i++)
    {
        s = s + ((pow(x,c)/factorial(c))*k);
        k=-k;
        c++;
    }
    printf("%0.2f\n",s);
    return 0;
}
