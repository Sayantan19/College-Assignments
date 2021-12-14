#include <stdio.h>
#include <math.h>
int gcd(int n1, int n2, int i,int f);

int main()
{
    int n1, n2,f = 1;
    printf("Enter the 2 numbers \n");
    scanf("%d %d", &n1, &n2);
    int c=gcd(n1,n2,2,f);
    printf("%d ",c);
    return 0;
}

int gcd(int n1, int n2, int i,int f)
{
    int min = (n1 > n2) ? n2 : n1;
    if (i <= min)
    {
        if (n1 % i == 0 && n2 % i == 0
        {
            f = f * i;
            n1 /= i;
            n2 /= i;
        }
        else
        i++;
        printf("%d ",f);
        gcd(n1,n2,i,f);
    }
    printf("\n");
    return f;
}
