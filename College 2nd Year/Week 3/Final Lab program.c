#include<stdio.h>
#include<stdlib.h>

#define max(a,b) ((a>b)?(a):(b))
// #define min(a,b) ((a<b)?(a):(b))

struct Poly{
    int deg;
    float * coeff;
};

struct Poly * create(int);
struct Poly * input(struct Poly *);
struct Poly * represent(int  );
struct Poly * sum(struct Poly *, struct Poly *);
struct Poly * PolyDerivative(struct Poly *);
void display(struct Poly *);

int main()
{
    int choice,deg1,deg2,deg3;
    struct Poly * poly1; 
    struct Poly * poly2;
    struct Poly * poly3;
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
            poly1 = represent(deg1);
            printf("The polynomial can be represented as : ");
            display(poly1);
            break;
            case 2:
            printf("Enter the degree of the first polynomial: ");
            scanf("%d",&deg1);
            printf("Enter the elements of the first polynomial\n");
            poly1 = represent(deg1);
            printf("Enter the degree of the second polynomial: ");
            scanf("%d",&deg2);
            printf("Enter the elements of the second polynomial\n");
            poly2 = represent(deg2);
            poly3 = sum(poly1,poly2);
            deg3 = max(deg1,deg2);
            printf("The sum of the polynomials are: ");
            display(poly3);
            break;
            case 3:
            printf("Enter the degree of the polynomial: ");
            scanf("%d",&deg1);
            printf("Enter the elements of the polynomial\n");
            poly1 = represent(deg1);
            poly2 = PolyDerivative(poly1);
            printf("The sum of the polynomials are: ");
            display(poly2);
            break;
            default:
            printf("Wrong choice!\n");
            break;
        }
        printf("Do you want to continue?[1/0]: ");
        int ch;
        scanf("%d",&ch);
        if(ch==0)
        exit(0);
    }while(1);

}

struct Poly * create(int n)
{
    struct Poly *a = (struct Poly *)malloc(sizeof(struct Poly));
    a->deg = n;
    a->coeff = (float *)malloc(sizeof(float)*a->deg);
    return a;
}

struct Poly * input(struct Poly * a)
{
    for(int i=0;i<a->deg+1;i++)
    {
        printf("Enter the coefficient of x^%d: ",i);
        scanf("%f",&a->coeff[i]);
    }
    return a;
}
struct Poly * represent(int deg)
{
    struct Poly * a = create(deg);
    a = input(a);
    return a;
}

void display(struct Poly * a)
{
    for(int i=a->deg;i>=1;i--)
    {
        if(a->coeff[i]<0&&a->coeff[i]!=-1)
            printf("%0.1fx^%d ",a->coeff[i],i);
        else if(a->coeff[i]==0)
            continue;
        else if(a->coeff[i]>0 && i!=(a->deg-1) && a->coeff[i]!=1)
            printf("+%0.1fx^%d ",a->coeff[i],i);
        else if(a->coeff[i]==1)
            printf("x^%d",i);
        else if(a->coeff[i]==-1)
            printf("-x^%d",i);
        else 
            printf("%0.1fx^%d ",a->coeff[i],i);
    }
    if(a->coeff[0]<0)
            printf("%0.1f ",a->coeff[0]);
    else
        printf("+%0.1f ",a->coeff[0]);
    printf("\n");
}

struct Poly * sum (struct Poly * poly1, struct Poly * poly2)
{
    struct Poly *c = create(max(poly1->deg,poly2->deg));
    c->deg = max(poly1->deg,poly2->deg);
    if(poly1->deg>poly2->deg)
        for(int i=0;i<=poly1->deg;i++)
            c->coeff[i] = poly1->coeff[i]; 
    else
        for(int i=0;i<=poly2->deg;i++)
            c->coeff[i] = poly2->coeff[i];
    if(poly1->deg>poly2->deg)
        for(int i=0;i<=poly2->deg;i++)
            c->coeff[i] = c->coeff[i]+poly2->coeff[i]; 
    else
        for(int i=0;i<=poly1->deg;i++)
            c->coeff[i] = c->coeff[i]+poly1->coeff[i];
    return c;
}

struct Poly * PolyDerivative(struct Poly *poly)
{
    struct Poly *der = create(poly->deg);
    der->deg = poly->deg-1;
    for(int i=0;i<poly->deg;i++)
        der->coeff[i] = poly->coeff[i+1]*(i+1);
    return der;
}