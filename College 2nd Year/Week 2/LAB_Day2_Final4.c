#include<stdio.h>
#include<stdlib.h>
int linearSearch(int*,int ,int);
int sentinelSearch(int *,int ,int);
int iterativebinary(int*,int,int,int);
int interpolationSearch(int*,int,int,int);

int main()
{
    int *arr,search,n,index,i,ch;

    printf("Enter the number of elements in array\n");  
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter elements (in ascending order)\n: ");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    while(1)
    {
        printf("Enter 1 for linear serach, 2 for sentinelSearch, 3 for iterativebinary, 4 for interpolationSearch, 5 for exit\n");
        {
            scanf("%d",&ch);
            switch (ch)
            {
                case 1:
                printf("Enter the number to be searched\n");
                scanf("%d",&search);
                index =  linearSearch(arr, n, search);
                if(index==-1)
                    printf("%d Not found \n",search);
                else 
                     printf("%d found at index =%d \n",search,index+1);  
                break;

                case 2:
                printf("Enter the number to be searched\n");
                scanf("%d",&search);
                index = sentinelSearch(arr,n,search);
                break;
                
                case 3:
                printf("Enter the number to be searched\n");
                scanf("%d",&search);
                index = iterativebinary(arr,n-1,0,search);
                if(index==0)
                printf("\nThe number, %d is not found in given Array", search);
                 else
                printf("\nThe number, %d found at Position %d", search, index);
                 break;
               
               case 4:
                printf("Enter the number to be searched\n");
                scanf("%d",&search);
                index = interpolationSearch(arr,n-1,0,search);
                if(index==-1)
                    printf("%d Not found \n",search);
                else 
                     printf("%d found at index =%d \n",search,index+1);  
                break;
                
                case 5:
                exit(0);

                default:
                printf("Wrong input!");
            }
                

        }
    }               return 0;
}
        int linearSearch(int arr[],int n,int search)
       {
                int i;
              for(i=0;i<n;i++)
            {
                if(search==arr[i])
                return i;
             }
                 return -1;
        }   

int sentinelSearch(int arr[],int n,int search)
{
    int i,last;
    last=arr[n-1];
    arr[n-1]=search;
    i=0;
    while(arr[i]!=search)
        i++;
    arr[n-1]=last;
    if(arr[i]==search)
    {
        printf("Search found at index %d\n",i+1);
    }
    else
    {
        printf("Not found\n");
    }

}
int iterativebinary(int arr[],int high,int low,int search)
{
    int middle;
    while(low <= high)
    {
        middle = (high+low)/2;
        if(arr[middle]<search)
            low = middle+1;
        else if(arr[middle]==search)
        {
            return (middle+1);
        }
        else
            high = middle-1;
    }
    return 0;
}
int interpolationSearch(int arr[],int high,int low,int search)
{
    while(low<=high && search>=arr[low] && search<=arr[high])
     {
         if(low==high)
         {
             if(arr[low]==search)
             return low;
             return 0;
         }
         int mid= low+(((double) (high-low) / (arr[high]-arr[low])) * (search-arr[low]));
         if(arr[mid]>search)
         {
             high =mid-1;
         }
         else if (arr[mid]==search)
         {
             return mid;
         }
            else
             low = mid+1;
     }
            return -1;
 }

