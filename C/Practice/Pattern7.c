#include <stdio.h>
#include <conio.h>
void main()
{
    int n = 5;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= n - i; j++)
            printf(" ");

        for (int j = 1; j <= (2 * i - 1); j++)
            printf("*");
        printf("\n");
    }
    for (int i = n-1; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
            printf(" ");

        for (int j = 1; j <= (2 * i - 1); j++)
            printf("*");

        printf("\n");
    }
}