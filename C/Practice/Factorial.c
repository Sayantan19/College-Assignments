#include<stdio.h>
long fact(int n)
{
    if(n<=1)
    return 1;
    else
    return n*fact(n-1);
}
void main()
{
    int n=5;
    printf("Factorial of %d is %ld",n,fact(n));
}