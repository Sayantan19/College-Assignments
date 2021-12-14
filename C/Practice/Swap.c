//WAP that swaps values of two variables using a third variable.
#include<stdio.h>
#include<conio.h>
int main()
{
    int a,b,c;
    printf("Enter 2 numbers \n");
    scanf("%d %d",&a,&b);
    printf("Before swapping %d %d\n",a,b);
    c=a;
    a=b;
    b=c;
    printf("After swapping %d %d\n",a,b);
    return 0;
}