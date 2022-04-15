#include<stdio.h>
#include<stdlib.h>


// -This function is for partitioning the array using the pivot.
// -The main point in focus is to take the pivot (the last element in our program)
// and then place it in its correct position. 
// -We set 2 counters, one (i) at the (start-1) position and the second(j) at (start) position.
// -We increment j if value of a[j] is greater than a[pivot].
// -Else, we increment i, swap the values of a[i] and a[j]. and then increment j
// -After the loop condition (j!=e) is met, control exits from the loop.
// -We finally swap a[i+1] with a[pivot]. the pivot element is now in its correct position.
int Partition (int * a,int s,int e)
{
    int i=s-1,j=s;
    int pivot=e;
    while(j!=e)
    {
        if(a[j]>a[pivot])
            j++;
        else
        {
            i=i+1;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j++;
        }
    }
    int temp = a[i+1];
    a[i+1] = a[pivot];
    a[pivot] = temp;
    return i+1;
}

// This function recursively calls the QuickSort function after finding out the Pivot element
// The idea is to Recursively sort the left and right of the pivot element

void QuickSort(int *a, int s,int e)
{
    if(s>=e)
        return;
    int pivot = Partition(a,s,e);
    QuickSort(a,s,pivot-1);
    QuickSort(a,pivot+1,e);
    return;
}

//Driver function

int main()
{
    int n;
    scanf("%d",&n);
    int *a = (int *) malloc(sizeof(int )*n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    QuickSort(a,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}