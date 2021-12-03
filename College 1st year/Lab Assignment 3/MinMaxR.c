#include<stdio.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
int minimum(int[],int);
int maximum(int[],int);
int main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Smallest element: %d\n",minimum(a,n));
    printf("Largest element: %d\n",maximum(a,n));
    return 0;
}

int minimum(int a[],int n)
{
    if(n==1)
        return a[0];
    return MIN(a[n-1],minimum(a,n-1));
}

int maximum(int a[],int n)
{
    if(n==1)
        return a[0];
    return MAX(a[n-1],maximum(a,n-1));
}