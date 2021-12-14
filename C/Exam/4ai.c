#include<stdio.h>
int main ()
{
    int m=1, n=1, r=1, s=3, t=5, x; x=++m && n++ && --r && s/2 && ++t;
    printf ("\nt=%d, x=%d",t, x);
    return 0;
}