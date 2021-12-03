#include<stdio.h>
void xstrtok(char *,char);
int main()
{
    char src[50],e;
    printf("Enter the source string: ");
    gets(src);
    printf("Enter the split element: ");
    scanf("%c",&e);
    xstrtok(src,e);
    return 0;
}

void xstrtok(char *a,char c)
{
    int i=0;
    while(a[i]!='\0')
    {
        if(a[i]==c)
            printf("\n");
        else
            printf("%c",a[i]);
        i++;
    }
}