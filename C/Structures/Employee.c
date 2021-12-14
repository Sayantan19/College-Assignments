#include <stdio.h>
int main()
{
    int n1 = 2, n2 = 3;
    int *p = &n1, *q = &n2;
    printf("%x %x \n", p, q);
    *p++ = *q++;
    printf("%x %x \n", p, q);    
    printf("The numbers are %d %d",n1, n2);
    return 0;
}