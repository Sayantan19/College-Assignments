#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int n,r,s=0;
    printf("Enter the number \n");
    scanf("%d",&n);
    int c=n;
    while(n>0)
    {
        n = n/2;
        s++;
    }
    int arr[s];
    int a=0;
    while(c>0)
    {
       r = c%2;
       arr[s] = r;   
       s--; 
       c/=2;
       a++;
    }    
    for(int i=0;i<=a;i++)
    printf("%d",arr[i]);
}