#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of rows \n");
    scanf("%d", &n);
    int a = 1,b;
    int c=n;
    for (int i = 1; i <=n ; i++)
    {
        b=i;
        for (int j = 1; j < c; j++)
            printf(" ");
        for (int j = 1; j <= i; j++)
        {
                printf("%d", b);
                b++;
        }
        // printf("\t %d",b);
        for(int j=2;j<=i;j++)
        {
            printf("%d",b-j);
        }
        a++;
        c--;
        printf("\n");
    }
}