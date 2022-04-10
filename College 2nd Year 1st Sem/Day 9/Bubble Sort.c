//Bubble Sorting algorithm.
//Involves in picking up an element, checking with all the other elements and then swapping them accordingly
//Result: the element eventually ends up in its correct position in each pass.

#include<stdio.h>
#include<stdlib.h>

int * BubbleSort(int * a,int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return a;
}

int main()
{
    int a[5] = {4,2,5,3,1};
    int * b = BubbleSort(a,5);
    for(int i=0;i<5;i++)
        printf("%d ",b[i]);
    printf("\n");
    return 0;
}