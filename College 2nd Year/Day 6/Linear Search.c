#include<stdio.h>
#include<stdlib.h>

int LinearSearch(int *,int ,int );
int * create(int);
int * input(int *,int );

int main()
{
    int n,* a,search;
    printf("Enter the number of elements of the array: ");
    scanf("%d",&n);
    create(n);
    printf("Enter the elements of the array:\n");
    a = input(a,n);
    printf("Enter the element you wish to search for: ");
    scanf("%d",&search);
    int x = LinearSearch(a,n,search);
    if(x!=0)
        printf("Element present in the array at position %d!\n",x);
    else
        printf("Element not present in the array!\n");
    return 0;
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