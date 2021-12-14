//WAP to swap two elements using the concept of pointers.
#include <stdio.h>
#include <conio.h>
int main()
{
    int x, y, *a, *b, temp;
    printf("Enter 2 numbers \n");
    scanf("%d %d", &x, &y);
    printf(" Before swapping %d %d \n", x, y);
    a = &x;
    b = &y;
    printf("%d %d",a ,b);

    temp = *b;
    *b = *a;
    *a = temp;

    printf(" After swapping %d %d \n", x, y);
    return 0;
}