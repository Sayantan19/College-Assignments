#include<stdio.h>
#include<stdlib.h>

int * create(int);
int * input(int *,int);
void display(int *,int);

int * reverse(int *,int );

int main()
{
    int n;
    printf("Enter the number of elements present in the array: ");
    scanf("%d",&n);
    int * arr = create(n);
    printf("Enter the elemenst of the array\n");
    arr = input(arr,n);
    arr = reverse(arr,n);
    printf("The reversed array is as follows\n");
    display(arr,n);
}

int * create(int n)
{
    int * a = (int *) malloc (sizeof(int)*n);
    return a;
}

int * input(int * a, int n)
{
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
       return a; 
}

void display(int * a,int n)
{
    for(int i=0;i<n;i++)
        printf("%d\n",a[i]);
}

int * reverse(int * a,int n)
{
    int k=n-1;
    if(n%2==0)
    {
        for(int i=0;i<n/2;i++)
        {
            int temp = a[i];
            a[i] = a[k];
            a[k]=temp;
            k--;
        }
    }
    else
    {
        for(int i=0;i<=(n-1)/2;i++)
        {
            int temp = a[i];
            a[i] = a[k];
            a[k]=temp;
            k--;
        }
    }
    return a;
}