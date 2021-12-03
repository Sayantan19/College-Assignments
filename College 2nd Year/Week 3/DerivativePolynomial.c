#include<stdio.h>
#include<stdlib.h>

int * create(int);
int * input(int *,int );
void display(int *,int);

int * PolyDerivative(int *,int);

int main()
{
    int *poly1,*poly2,deg1;
    printf("Enter the degree of the polynomial: ");
    scanf("%d",&deg1);
    poly1 = create(deg1);
    printf("Enter the coefficients of the polynomial:\n");
    poly1 = input(poly1,deg1+1);
    poly2 = PolyDerivative(poly1,deg1+1);
    display(poly2,deg1);
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

int * PolyDerivative(int *poly,int deg)
{
    int *der = create(deg);
    for(int i=0;i<deg+1;i++)
        der[i] = poly[i+1]*(i+1);
    return der;
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



