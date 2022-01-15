#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ABC.c"

void main1()
{
    int n;
    printf("Enter a value between 0 and 3: ");
    scanf("%d",&n);
    char from = 'A',to = 'C',aux = 'B';
    Tower(n,from,to,aux);
}

void main2()
{
    int a,b;
    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);
    printf("The GCD of the 2 numbers is: %d\n",GCD(((a>b)?(a):(b)),((a<b)?(a):(b))));
    // return 0;
}

void main3()
{
    int n,* a,search;
    printf("Enter the number of elements of the array: ");
    scanf("%d",&n);
    create(n);
    printf("Enter the elements of the array:\n");
    a = input(a,n);
    printf("Enter the element you wish to search for: ");
    scanf("%d",&search);
    int x = LinearSearch(a,n,search);
    if(x!=0)
        printf("Element present in the array at position %d!\n",x);
    else
        printf("Element not present in the array!\n");
    // return 0;
}