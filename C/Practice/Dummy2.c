#include <stdio.h>
int main()
{
    int a = 0, b = -1, c = 1, d = 3, e = 5, x;
    x = a++ || b + 1 || --c || d / 2 || ++e;
    printf("a = % d b = % d c = % d d = % d e = % d x = % d\n", a, b, c, d, e, x);
    return 0;
}