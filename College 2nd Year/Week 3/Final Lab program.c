#include<stdio.h>
#include<stdlib.h>

#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

int * create(int);
int * input(int *,int);
int * represent(int  );
int * sum(int *,int , int *,int);
int * PolyDerivative(int *,int);
void display(int *,int);

int main()
{
    int choice,deg1,deg2,deg3;
    int * poly1; 
    int * poly2;
    int * poly3;
    do
    {
        printf("1 for Representing the Polynomial\n2 for finding Sum of 2 Polynomials\n3 for Finding the Derivative of a Polynomial\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the degree of the polynomial: ");
            scanf("%d",&deg1);
            printf("Enter the elements of the polynomial\n");
            poly1 = represent(deg1+1);
            printf("The polynomial can be represented as : ");
            display(poly1,deg1+1);
            break;
            case 2:
            printf("Enter the degree of the first polynomial: ");
            scanf("%d",&deg1);
            printf("Enter the elements of the first polynomial\n");
            poly1 = represent(deg1+1);
            printf("Enter the degree of the second polynomial: ");
            scanf("%d",&deg2);
            printf("Enter the elements of the second polynomial\n");
            poly2 = represent(deg2+1);
            poly3 = sum(poly1,deg1+1,poly2,deg2+1);
            deg3 = max(deg1,deg2);
            printf("The sum of the polynomials are: ");
            display(poly3,deg3+1);
            break;
            case 3:
            printf("Enter the degree of the polynomial: ");
            scanf("%d",&deg1);
            printf("Enter the elements of the polynomial\n");
            poly1 = represent(deg1+1);
            poly2 = PolyDerivative(poly1,deg1+1);
            printf("The sum of the polynomials are: ");
            display(poly2,deg2+1);
            break;
            default:
            printf("Wrong choice!");
            break;
        }
        printf("Do you want to continue?[1/0]: ");
        int ch;
        scanf("%d",&ch);
        if(ch==0)
        exit(0);
    }while(1);

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
    int *a = create(deg);
    a = input(a,deg);
    return a;
}

void display(int *a,int n)
{
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]<0&&a[i]!=-1)
            printf("%dx^%d ",a[i],i);
        else if(a[i]==0)
            continue;
        else if(a[i]>0 && i!=(n-1) && a[i]!=1)
            printf("+%dx^%d ",a[i],i);
        else if(a[i]==1)
            printf("x^%d",i);
        else if(a[i]==-1)
            printf("-x^%d",i);
        else 
            printf("%dx^%d ",a[i],i);
    }
    if(a[0]<0)
            printf("%d ",a[0]);
    else
        printf("+%d ",a[0]);
    printf("\n");
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

int * PolyDerivative(int *poly,int deg)
{
    int *der = create(deg);
    for(int i=0;i<deg;i++)
        der[i] = poly[i+1]*(i+1);
    return der;
}