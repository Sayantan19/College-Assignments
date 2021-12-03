#include<stdio.h>
#include<stdlib.h>
int * create(int);
int * input(int *,int);
void display(int );

int * SortArray(int *, int );
int  BinarySearchIterative(int *,int ,int,int);

int main()
{
    int n,search;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int *arr;
    arr = create(n);
    printf("Enter the elements of the array\n");
    arr = input(arr,n);
    printf("Enter the element you want to search for: ");
    scanf("%d",&search);
    // int occurance = SearchOccurance(*arr,n,search);
    display(BinarySearchIterative(arr,n-1,0,search));
}

int * create(int n)
{
    int *a = (int *)malloc(n * sizeof(int));
    return a;
}

int * input(int *a,int n)
{
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    return a;
}

int * SortArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    return a;
}
int BinarySearchIterative(int *b, int hi,int lo,int s)
{
    int *a = SortArray(b,hi);
    while(lo<=hi)
    {
        int mid = (hi+lo)/2;
        if(a[mid]>s)
        {
            hi = mid-1;    
        }
        else if(a[mid]==s)
        {
            return 1;
        }
        else
            lo = mid+1;
    }
    return 0;
}

void display(int a)
{
    if(a==1)
        printf("Element is present in the array\n");
    else
        printf("Element is not present in the array\n");

}