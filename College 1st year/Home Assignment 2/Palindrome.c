#include<stdio.h>
int main()
{
    int n,s=0,rev=0,count=0;
    printf("Enter a number ");
    scanf("%d",&n);
    int c=n;
    while(c>0)
    {
        int r = c%10;
        s = s+r;
        rev = rev*10+r;
        c/=10;
        count++;
    }
    printf("Number of digits in the number= %d\n",count);
    printf("Sum of digits = %d\n",s);
    if(rev==n)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
    return 0;
}