#include<stdio.h>
#include<math.h>
#include<string.h>
void factorial(int);
void prime(int);
void palindrome(int);
void main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    while(1)
    {
        int c;
        printf("1 for factorial\n2 for prime check\n3 for palindrome check\nPick your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            factorial(n);
            break;
            case 2:
            prime(n);
            break;
            case 3:
            palindrome(n);
            break;
            default:
            printf("Wrong choice\n");
        }
        char ch[1];
        printf("Do you want to continue [y/n]: ");
        scanf("%s",ch);
        if(ch[0]=="n")
            break;
    }
}

void factorial(int n)
{
    int f=1;
    for(int i=1;i<=n;i++)
        f=f*i;
    printf("The factorial of %d is %d\n",n,f);
}

void prime(int n)
{
    int flag=0;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i == 0)
        {
            flag = 0;
            break;
        }
    }
    if(flag == 1)
        printf("Prime Number\n");
    else
        printf("Not a Prime Number\n");
}

void palindrome(int n)
{
    int d=n,rev=0;
    while(d>0)
    {
        int r = d%10;
        rev = rev*10 + r;
        d/=10;
    }
    if(n==rev)
        printf("The given number is a palindrome number\n");
    else
        printf("The given number is not a palindrome number\n");
}   

