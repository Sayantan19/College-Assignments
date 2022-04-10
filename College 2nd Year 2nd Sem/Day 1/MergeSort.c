#include<stdio.h>
#include<stdlib.h>
 
void merge(int * a,int s,int e)
{
    int i=s;
    int m = (s+e)/2;
    int j = m+1;
    int k=0;
    int * b = (int *)malloc(sizeof(int)*(e-s));
    while(i<=m && j<=e)
    {
        if(a[i]<a[j])
        {
            b[k++] = a[i];
            i++;
        }
        
        else
        {
            b[k++] = a[j];
            j++;
        }
    }
    while(i<=m)
        b[k++] = a[i++];
    while(j<=e)
        b[k++] = a[j++];
    int idx = 0;
    for(k=s;k<=e;k++)
    {
        a[k] = b[idx];
        idx++;
    }
    return;
}

void MergeSort(int * a,int s,int e)
{
    if(s>=e)
        return;
    int mid = (s+e)/2;
    MergeSort(a,s,mid);
    MergeSort(a,mid+1,e);
    merge(a,s,e);
    return;
}

int main()
{
    int n;
	printf("Enter the number of elements in the array: ");
	scanf("%d",&n);
	int * arr = (int *) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	    scanf("%d",&arr[i]);
    MergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
        

