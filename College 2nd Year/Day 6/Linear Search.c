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
    if(x==1)
        printf("Element present in he array!\n");
    else
        printf("Element not present in he array!\n");
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
    int * arr = create(n-1);
    int x = a[0];
    for(int i=0;i<n-1;i++)
        arr[i] = a[i+1];
    if(x==search)
        return 1;
    else if(n!=0)
        return LinearSearch(arr,n-1,search);
    else
        return 0;
}