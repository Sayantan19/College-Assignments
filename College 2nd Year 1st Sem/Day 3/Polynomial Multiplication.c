#include<stdio.h>
#include<stdlib.h>

int * create(int);
int * input(int,int *);
int * represent(int);
int * multiply(int *,int *,int ,int,int );
void display(int *,int);

int main()
{
    int deg1,deg2;
    int * poly1;
    int * poly2;
    printf("Enter the degree of the first polynomial: ");
    scanf("%d",&deg1);
    printf("Enter the degree of the second polynomial: ");
    scanf("%d",&deg2);
    printf("Enter the elements of the first polynomial: ");
    poly1 = represent(deg1+1);
    printf("Enter the elements of the second polynomial: ");
    poly2 = represent(deg2+1);
    int deg3 = deg1+deg2+1;
    int * poly3;
    poly3 = multiply(poly1,poly2,deg1+1,deg2+1,deg3+1);
    printf("The product of the 2 polynomials is: ");
    display(poly3,deg3);
    return 0;
}

int * represent(int deg)
{
    int *a;
    a = create(deg);
    a = input(deg,a );
    return a; 
}

int * create(int n)
{
    int * a = (int *)malloc(sizeof(int) * n) ;
    return a;
}

int * input(int deg,int * poly )
{
    for(int i=0;i<deg;i++)
    {
        printf("Enter the coefficients of x^%d: ",i);
        scanf("%d",&poly[i]);
    }
    return poly;
}

int * multiply(int * poly1,int * poly2, int deg1, int deg2, int deg3)
{
    int * poly3;
    poly3 = create(deg3);
    for(int i=0;i<deg3;i++)
        poly3[i] = 0;
    for(int i=0;i<deg1;i++)
        for(int j=0;j<deg2;j++)        
            poly3[i+j] = poly3[i+j] +  poly1[i] * poly2[j];
    return poly3;
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