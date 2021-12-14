#include<stdio.h>
int palindrome(int n);

int main()
{
    int n;
    printf("enter a number\n");
    scanf("%d",&n);
    if(n==palindrome(n))
    printf("Given number is a palindrome number");
    else
    printf("Given number is not a palindrome number");
}

int palindrome(int n)
{
    int r,s=0;
    while(n>0)
    {
        r=n%10;
        s = s*10+r;
        n/=10;
    }
    return s;
}