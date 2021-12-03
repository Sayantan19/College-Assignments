#include<stdio.h>
#include<stdlib.h>

int * create(int);
int * input(int *,int);
void display(int );

int * SortArray(int *, int );
int  LinearSearch(int *,int ,int);
int  LinearSentinelSearch(int *,int ,int);
int  BinarySearchIterative(int *,int ,int,int);
int  InterpolationSearchIterative(int *,int ,int,int);

int main()
{
    int n,search;
    int *arr;
    while(1)
    {
        printf("Enter 1 for Linear or Linear Sentinel Searches\n");
        printf("Enter 2 for Binary or Interpolation Searches\n");
        printf("Enter your choice: \n");
        int choice1,choice2;
        scanf("%d",&choice1);
        switch(choice1)
        {
            case 1:
            printf("Enter the number of elements in the array: ");
            scanf("%d",&n);
            arr = create(n);
            printf("Enter the elements of the array\n");
            arr = input(arr,n);
            printf("Enter 1 for Linear Search\n");
            printf("Enter 2 for Linear Sentinel Search\n");
            printf("Enter your choice: \n");
            scanf("%d",&choice2);
            switch(choice2)
            {
                case 1:
                printf("Enter the element you want to search for: ");
                scanf("%d",&search);
                display(LinearSearch(arr,n,search));
                break;
                case 2:
                printf("Enter the element you want to search for: ");
                scanf("%d",&search);
                display(LinearSentinelSearch(arr,n,search));
                break;
                default:
                printf("Wrong Choice\n");
            }
            break;
            case 2:
            printf("Enter the number of elements in the array: ");
            scanf("%d",&n);
            arr = create(n);
            printf("Enter the elements of the array (A sorted array please!)\n");
            arr = input(arr,n);
            printf("Enter 1 for Binary Search\n");
            printf("Enter 2 for Interpolation Search\n");
            printf("Enter your choice: \n");
            scanf("%d",&choice2);
            int hi,lo;
            switch(choice2)
            {
                case 1:
                printf("Enter the lower index you want to search within: ");
                scanf("%d",&lo);
                printf("Enter the upper index you want to search within: ");
                scanf("%d",&hi);
                printf("Enter the element you want to search for: ");
                scanf("%d",&search);
                display(BinarySearchIterative(arr,hi,lo,search));
                break;
                case 2:
                printf("Enter the lower index you want to search within: ");
                scanf("%d",&lo);
                printf("Enter the upper index you want to search within: ");
                scanf("%d",&hi);
                printf("Enter the element you want to search for: ");
                scanf("%d",&search);
                display(InterpolationSearchIterative(arr,hi,lo,search));
                break;
                default:
                printf("Wrong Choice\n");
            }
            break;
            default:
            printf("Wrong Choice\n");
        }
        printf("Do you want to continue[1/0]: ");
        int e;
        scanf("%d",&e);
        if(e!=1)
            exit(0);
    }
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

int  LinearSearch(int *a, int n,int s)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==s)
        {
            return i;
        }
    }
    return -1;
}

int  LinearSentinelSearch(int *a, int n,int s)
{
    int last = a[n-1];
    a[n-1] = s;
    int i=0;
    while(a[i]!=s)
    i++;
    a[n-1] = last;
    if((i<n-1)||(a[n-1]==s))
        return i;
    return -1;
}

int BinarySearchIterative(int *a, int hi,int lo,int s)
{
    // int *a = ArraySort(b,hi);
    while(lo<=hi)
    {
        int mid = (hi+lo)/2;
        if(a[mid]>s)
        {
            hi = mid-1;    
        }
        else if(a[mid]==s)
        {
            return mid;
        }
        else
            lo = mid+1;
    }
    return -1;
}

int InterpolationSearchIterative(int *a, int hi,int lo,int s)
{
    // int *a = SortArray(b,hi);
    while(lo<=hi && s>=a[lo] && s<=a[hi])
    {
        if(lo == hi)
        {
            if(a[lo] == s)
                return lo;
            return -1;
        }
        int mid = lo + (((hi-lo)/(a[hi]-a[lo]))*(s-a[lo]));
        if(a[mid]>s)
        {
            hi = mid-1;    
        }
        else if(a[mid]==s)
        {
            return mid;
        }
        else
            lo = mid+1;
    }
    return -1;
}

void display(int a)
{
    if(a>=0)
        printf("Element is present in the array at %d position\n",a);
    else
        printf("Element is not present in the array\n");

}