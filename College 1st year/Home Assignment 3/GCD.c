#include <stdio.h>
 
// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
// Driver program to test above function
int main()
{
    int a,b;
    printf("Enter the 2 numbers: ");
    scanf("%d",&a);
    scanf("%d",&b);
    printf("GCD of %d and %d is %d \n", a, b, gcd(a, b));
    return 0;
}