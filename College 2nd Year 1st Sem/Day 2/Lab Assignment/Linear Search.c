#include<stdio.h>
#include<stdlib.h>
int * create(int);
int * input(int *,int);
void display(int );

int  LinearSearch(int *,int ,int);

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
    display(LinearSearch(arr,n,search));
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
    int *ind;
    ind = create(n);
    int index=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]==s)
        {
            return 1;
        }
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
