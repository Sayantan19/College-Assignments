#include<stdio.h>
#include<stdlib.h>

typedef struct Complexnumber
{
    float real;
    float imaginary;
}com;


com * create();
com * input(com *);
void display(com *);

com * add(com *, com *);
com * subtract(com *,com *);
com * multiply(com *,com *);
com * divide(com *,com *);

int main()
{
    int choice;
    com *a,*b,*s,*d,*p,*q;
    do
    {
        printf("Enter the coefficients of the first complex number\n");
        a = input(a);
        printf("Enter the coefficients of the second complex number\n");
        b = input(b);
        printf("1 for addition\n2 for subtraction\n3 for multiplication\n4 for division\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                s = add(a,b);
                printf("The sum is: ");
                display(s);
                break;
            case 2:
                d = subtract(a,b);
                printf("The difference is: ");
                display(d);
                break;
            case 3:
                p = multiply(a,b);
                printf("The product is: ");
                display(p);
                break;
            case 4:
                q = divide(a,b);
                printf("The quotient is: ");
                display(q);
                break;
            default:
                printf("Wrong choice!\n");
        }
        int ch;
        printf("Do you want to continue?[1/0]\n");    
        scanf("%d",&ch);
        if(ch==0)
            exit(0);
    }while(1);
    return 0;
}

com * create()
{
    com * c;
    c = (com *)malloc(sizeof(com));
    return c;
}

com * input(com * c)
{
    c = create();
    printf("Enter the real coefficient: ");
    scanf("%f",&c->real);
    printf("Enter the imaginary coefficient: ");
    scanf("%f",&c->imaginary);
    return c;
}

com * add(com * a,com * b)
{
    com * c;
    c = create();
    c->real = a->real+b->real;
    c->imaginary = a->imaginary+b->imaginary;
    return c;
}

com * subtract(com * a,com * b)
{
    com * c;
    c = create();
    c->real = a->real-b->real;
    c->imaginary = a->imaginary-b->imaginary;
    return c;
}

com * multiply(com * a,com * b)
{
    com * c;
    c = create();
    c->real = (a->real * b->real) - (a->imaginary * b->imaginary);
    c->imaginary = (a->real * b->imaginary) + (a->imaginary * b->real);
    return c;
}

com * divide(com * a,com * b)
{
    com * c,* d,* n, * q;
    c = create();
    c->real = b->real;
    c->imaginary = -b->imaginary;
    d = create();
    d = multiply(b,c);
    n = create();
    n = multiply(a,c);
    q = create();
    q->real = n->real/d->real;
    q->imaginary = n->imaginary/d->real;
    return q;
}

void display(com *a)
{
    if(a->real>0)
        printf("%0.4f",a->real);
    else    
        printf("%0.4f",a->real);
    if(a->imaginary>0)
        printf("+%0.4fi\n",a->imaginary);
    else    
        printf("%0.4fi\n",a->imaginary);
}