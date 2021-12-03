#include<stdio.h>
#include<stdlib.h>

int * create(int);
int * input(int *,int);
void display(int *,int);
int * represent(int  );

int main()
{
    int deg;
    printf("Enter the degree of polynomial: ");
    scanf("%d",&deg);
    int *rep = represent(deg);
    display(rep,(deg+1));
}

int * create(int n)
{
    int *a = (int *)malloc(n * sizeof(int));
    return a;
}

int * input(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter the coefficient of x^%d: ",i);
        scanf("%d",&a[i]);
    }
    return a;
}
int * represent(int deg)
{
    int *a = create(deg+1);
    a = input(a,deg+1);
    return a;
}

void display(int *a,int n)
{
    printf("The polynomial can be represented as: ");
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]<0)
            printf("%dx^%d",a[i],i);
        else if(a[i]==0)
            continue;
        else if(a[i]>0 && i!=(n-1))
            printf("+%dx^%d",a[i],i);
        else 
            printf("%dx^%d",a[i],i);
    }
    if(a[0]<0)
            printf("%d",a[0]);
    else
        printf("+%d",a[0]);
    printf("\n");
}

