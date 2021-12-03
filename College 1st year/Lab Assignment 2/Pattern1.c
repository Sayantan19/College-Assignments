#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of rows\n");
    scanf("%d",&n);
    int c=n;
    for(int i=1;i<=n;i++)
    {
        int r=i;
        for(int j=1;j<c;j++)
        printf("\t");
        c--;
        for(int j=1;j<=i;j++)
        {
            printf("%d\t",r);
            r++;
        }
        r=r-1;
        for(int j=1;j<i;j++)
        {
            r--;
            printf("%d\t",r);
        }
        printf("\n");
    }
    return 0;
}
