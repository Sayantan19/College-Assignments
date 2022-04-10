#include<stdio.h>
#include<stdlib.h>

int recursiveBinary(int arr[],int low,int high,int search)
{
    int middle;
    middle = (high+low)/2;
	if(low>high)
     	return -1;
        
    else if(arr[middle]==search)
		return middle;
        
	else if(arr[middle]<search)
        recursiveBinary(arr,middle+1,high,search);
        
    else if(arr[middle]>search)
        recursiveBinary(arr,low,middle,search);
}

int main()
{
	int search,index;
	int n;
	printf("Enter the number of elements in the array: ");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	    scanf("%d",&arr[i]);
	printf("Enter the number to be searched\n");
    scanf("%d",&search);
    index = recursiveBinary(arr,0,n-1,search);
    if(index==-1)
    	printf("Not present \n");
    else
    	printf("Element at index: %d\n",index);
	return 0;
}

