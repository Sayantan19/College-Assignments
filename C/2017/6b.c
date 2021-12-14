#include <stdio.h>
int reverse(int n, int s);

int main()
{
    int n, rev = 0;
    printf("Enter a number \n");
    scanf("%d", &n);
    int c = reverse(n, rev);
    printf("reverse of the given number is %d", c);
    return 0;
}

int reverse(int n, int s)
{
    int x;
    x = n % 10;
    s = s * 10 + x;
    n /= 10;
    if (n > 0)
    {
        reverse(n, s);
    }
    else
        return s;
}