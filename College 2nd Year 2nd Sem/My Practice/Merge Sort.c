#include<stdio.h>
#include<stdlib.h>

void merge(int *a, int s,int e)
{
    int i=s;
    int mid = (s+e)/2;
    int j=mid+1;
    int * b = (int *)malloc(sizeof(int)*(e-s));
    int k=0;
    while(i<=mid && j<=e)
    {
        if(a[i]<a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while(i<=mid)
        b[k++] = a[i++];
    while(j<=e)
        b[k++] = a[j++];
    int idx = 0;
    for(k=s;k<=e;k++)
        a[k] = b[idx++];
    return;
}

void MergeSort(int *a, int low, int high)
{
    if(low>=high)
        return;
    int mid = (high+low)/2;
    MergeSort(a,low,mid);
    MergeSort(a,mid+1,high);
    merge(a,low,high);
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    int *a = (int *) malloc(sizeof(int )*n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    MergeSort(a,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}