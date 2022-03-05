//Insertion Sort
//Takes the array. divides it into 2 parts. the 1st part is the sorted part, and the 2nd part is the unsorted one.
//Takes one element from the unsorted part, and places it into the sorted part

#include<stdio.h>
#include<stdlib.h>

int * InsertionSort(int * a,int n)
{
    int temp;
    for(int i=1;i<n;i++)
    {
        temp = a[i];
        int j=i-1;
        while(j>=0 && temp<a[j])
        {
            a[j+1] = a[j];
            j--;
        } 
        a[j+1] = temp;
    }
    return a;
}

int main()
{
    int a[5] = {4,2,5,3,1};
    int * b = InsertionSort(a,5);
    for(int i=0;i<5;i++)
        printf("%d ",b[i]);
    printf("\n");
    return 0;
}
