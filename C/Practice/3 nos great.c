#include<stdio.h>
void main()
{
    int a,b,c;
    printf("Enter 3 numbers \n");
    scanf("%d %d %d",&a,&b,&c);
    if(a>b)
    {
        if(a>c)
        printf("%d is the greatest number \n",a);
        else
        printf("%d is the greatest number \n",c);
    }
    else
    printf("%d is the greatest number \n",b);
}