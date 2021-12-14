#include<stdio.h>
#include<conio.h>
#include<math.h>
int arm(int n)
{
    int r,s=0,c=n;
    while(n>0)
    {
        r=n%10;
        s+=(int)pow(r,3);
        n/=10;
    }
    if(c==s)
        return 1;
    else
        return 0; 
}

void main()
{
    int n;
    printf("Enter a number \n");
    scanf("%d",&n);
    if(arm(n)==1)
        printf("%d is an Armstrong Number",n);
    else
        printf("%d is not an Armstrong Number",n);    
}