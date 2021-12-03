#include<stdio.h>
int max(int[],int);
int max2(int[],int);

int main()
{
    int n;
    printf("Enter the length of array: ");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Largest element is: %d",max(a,n));
    printf("\nSecond largest element is: %d\n",max2(a,n));
    return 0;
}

int max(int a[],int n)
{
    int max = 0;
    for(int i=0;i<n;i++)
        max = a[i]>max?a[i]:max;
    return max;
}

int max2(int a[],int n)
{
    int max2=0;
    int maxi = max(a,n);
    for(int i=0;i<n;i++)
    {
        if(a[i]>max2&&a[i]!=maxi)
            max2 = a[i];
    }
    return max2;
}