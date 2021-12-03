//This program accurately prints factorial for single digit numbers
#include<stdio.h>
int main()
{
    int f=1;
    int n;
    printf("Enter a number ");
    scanf("%d",&n);
    if(n<10)
    {
        for(int i=1;i<=n;i++)
        f*=i;
        printf("The factorial of %d is %d\n",n,f);
    }
    else
        printf("Not in the domain of program \n");
    return 0;
}
