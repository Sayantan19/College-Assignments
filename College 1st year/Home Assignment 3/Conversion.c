#include<stdio.h>
#include<math.h>
void D2B(long int);
int B2D(long int);
int B2O(long int);
void O2B(long int);
void D2O(long int);
int O2D(long int);
int main()
{
    int ch,b;
    long int n;
    printf("Enter a the number: ");
    scanf("%ld",&n);
    printf("Enter the base: ");
    scanf("%d",&b);
    if(b==2)
    {
        do
        {
            printf("1 for B2D\n2 for B2O\nEnter your choice: ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                printf("The number in decimal form is: %d",B2D(n));
                break;
                case 2:
                printf("The number in octal form is: %d",B2O(n));
                break;
            }
            printf("\nDo you want to repeat? [y/n]: ");
            char c[1];
            scanf("%s",c);
            if(c[0]=='n')
                return 0;
        }while(1);
    }
    if(b==8)
    {
        do
        {
            printf("1 for O2B\n2 for O2D\nEnter your choice: ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                O2B(n);
                break;
                case 2:
                printf("The number in decimal form is: %d",O2D(n));
                break;
            }
            printf("\nDo you want to repeat? [y/n]: ");
            char c[1];
            scanf("%s",c);
            if(c[0]=='n')
                return 0;
        }while(1);
    }
    if(b==10)
    {
        do
        {
            printf("1 for D2B\n2 for D2O\nEnter your choice: ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                D2B(n);
                break;
                case 2:
                D2O(n);
                break;
            }
            printf("\nDo you want to repeat? [y/n]: ");
            char c[1];
            scanf("%s",c);
            if(c[0]=='n')
                return 0;
        }while(1);
    }
}

void D2B(long int n)
{
    int c=0;
    int b[100];
    while(n>0)
    {
        int r = n%2;
        b[c] = r;
        c++;
        n/=2;
    }
    printf("The number in binary form is: ");
    for(int i=c-1;i>=0;i--)
        printf("%d",b[i]);
}

int B2D(long int n)
{
    int d=0,c=0;
    while(n>0)
    {
        int r=n%10;
        d = d+(int)pow(2,c)*r;
        n/=10;
        c++;
    }
    return d;
}

int B2O(long int n)
{
    int o=0,d=0,i=0;
    while (n != 0)
    {
        int temp=n%1000;
        o+=B2D(temp)*(int)pow(10, i++);
        n=n/1000;
    }
    return o;
}

int O2D(long int n)
{
    int r,d=0,c=0;
    while(n>0)
    {
        r=n%10;
        d = d+(int)pow(8,c)*r;
        n/=10;
        c++;
    }
    return d;
}

void O2B(long int n)
{
    int d;
    d = O2D(n);
    D2B(d);
}

void D2O(long int n)
{
    long remainder, quotient;
    int octal[100], i = 1, j;
    quotient = n;
    while (quotient != 0)
    {
        octal[i++] = quotient % 8;
        quotient = quotient / 8;
    }
    printf("The octal form of the number is: ");
    for (j = i - 1; j > 0; j--)
        printf("%d", octal[j]);
}