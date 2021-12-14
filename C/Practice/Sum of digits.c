#include<stdio.h>
#include<conio.h>
void main()
{
    int num,sum=0,r;
    printf("Enter a number \n");
    scanf("%d",&num);
    while(num>0)
    {
        r=num%10;
        sum+=r;
        num=num/10;
    }
    printf("The sum of the digits of the number is %d",sum);
}