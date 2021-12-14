#include<stdio.h>
int main()
{
    int arr[100],n,search;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the number you want to search\n");
    scanf("%d",&search);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==search)
        {
            printf("Number found at %d ",(i+1));
            return 0;
        }
    }
    printf("Element does not exist");
    return 0;
}