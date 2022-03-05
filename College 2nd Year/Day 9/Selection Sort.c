//Selection Sort.
//Involves in finding the minimum value in the array and swapping them with the ith position of the loop
//"Selects" element and places it in its correct position

#include<stdlib.h>
#include<stdio.h>

int * SelectionSort(int * a,int n)
{
    int min = 0,temp;
    for(int i=0;i<n-1;i++)
    {
        min = i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min = j;
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
    return a;
}

int main()
{
    int a[5] = {4,2,5,3,1};
    int * b = SelectionSort(a,5);
    for(int i=0;i<5;i++)
        printf("%d ",b[i]);
    printf("\n");
    return 0;
}