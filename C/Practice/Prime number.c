#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int num;
    printf("Enter a number \n");
    scanf("%d",&num);
    int flag=0;
    if(num!=2)
    {
        for(int i=2;i<=sqrt(num);i++)
        {
            if(num%i==0)
            flag=1;
            break;
        }
    }
    if(flag!=1)
        printf("%d is a prime number \n",num);
    else    
        printf("%d is not a prime number \n",num);
}