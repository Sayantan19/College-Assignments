#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Tower(int n,char from,char to,char aux)
{
    if(n==0)
        return;
    Tower(n-1,from,aux,to);
    printf("Disk %d moved from %c to %c\n",n,from,aux);
    Tower(n-1,from,to,aux);
}

int GCD(int a, int b)
{
    if(a%b==0)
        return b;
    return GCD(a%b,a);
}

int * create(int n)
{
    int * arr = (int *) malloc (sizeof(int) * n);
    return arr;
}

int * input(int *a,int n)
{
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    return a;
}

int LinearSearch(int * a,int n,int search)
{
    if(n>=0)
    {
       if(a[n-1] == search)
        {
            return n;
        }
        else
        {
            return LinearSearch(a, n-1, search);
        }
    }
    return 0;
}