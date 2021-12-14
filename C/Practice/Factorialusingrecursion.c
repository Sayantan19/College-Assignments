#include<stdio.h>
#include<conio.h>

int factorial(int n)
{
    if(n==1||n==0)
    return 1;
    else
    return (n*factorial(n-1));
}

void main()
{
    int num;
    printf("Enter the number \n");
    scanf("%d",&num);
    printf("The factorial of %d is %d \n",num,factorial(num));
}