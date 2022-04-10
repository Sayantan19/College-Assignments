#include <stdio.h>
#include <stdlib.h>
int GCD(int, int);
int main()
{
    int a,b;
    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);
    printf("The GCD of the 2 numbers is: %d\n",GCD(((a>b)?(a):(b)),((a<b)?(a):(b))));
    return 0;
}
int GCD(int a, int b)
{
    if(a%b==0)
        return b;
    return GCD(a%b,a);
}
