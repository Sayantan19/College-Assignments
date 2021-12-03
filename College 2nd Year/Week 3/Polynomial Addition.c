#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

int * create(int);
int * input(int *,int);
void display(int *,int);
int * represent(int  );
int * sum(int *,int , int *,int);
int main()
{
    int deg1,deg2,deg3;
    printf("Enter the degree of first polynomial: ");
    scanf("%d",&deg1);
    printf("Enter the degree of second polynomial: ");
    scanf("%d",&deg2);
    printf("Enter the co-efficients of the first polynomial:\n");
    int *poly1 = represent(deg1);
    printf("Enter the co-efficients of the second polynomial:\n");
    int *poly2 = represent(deg2);
    deg3 = max(deg1,deg2);
    int *poly3 = sum(poly1,deg1,poly2,deg2);
    display(poly3,(deg3+1));
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

int * sum(int *a,int d1,int *b,int d2)
{
    int *c = create(max(d1,d2));
    if(d1>d2)
        for(int i=0;i<=d1;i++)
            c[i] = a[i]; 
    else
        for(int i=0;i<=d2;i++)
            c[i] = b[i];
    if(d1>d2)
        for(int i=0;i<=d2;i++)
            c[i] = c[i]+b[i]; 
    else
        for(int i=0;i<=d1;i++)
            c[i] = c[i]+a[i];
    return c;
}

int * represent(int deg)
{
    int *a = create(deg+1);
    a = input(a,deg+1);
    return a;
}

void display(int *a,int n)
{
    printf("The sum of the 2 polynomials is: ");
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