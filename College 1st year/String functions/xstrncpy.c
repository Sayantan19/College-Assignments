#include<stdio.h>
void xstrncpy(char *,int,char *);
int main()
{
    char src[50],dest[50];
    int n;
    printf("Enter the source string: ");
    gets(src);
    printf("Enter the value of n: ");
    scanf("%d",&n);
    xstrncpy(src,n,dest);
    return 0;
}

void xstrncpy(char *a,int n,char *b)
{
    for(int i=0;i<n;i++)
        b[i] = a[i];
    b[n] = '\0';
    printf("The Final string is: %s\n",b);
}