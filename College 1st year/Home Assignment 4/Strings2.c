#include<stdio.h>
void xcat(char *,char *);
void xcmp(char *,char *);
void xreverse(char *);
int main()
{
    int choice;
    char a[100],b[100];
    while(1)
    {
        printf("1 for concatenation\n2 for comparison\n3 for string reversal\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter string 1: ");
            scanf("%s",a);
            printf("Enter string 2: ");
            scanf("%s",b);
            xcat(a,b);
            break;
            case 2:
            printf("Enter string 1: ");
            scanf("%s",a);
            printf("Enter string 2: ");
            scanf("%s",b);
            xcmp(a,b);
            break;
            case 3:
            printf("Enter string : ");
            scanf("%s",a);
            xreverse(a);
            break;
        }
        char e[1];
        printf("Do you want to continue:[y/n]: ");
        scanf("%s",e);
        if(e[0]!='y')
            break;
    }
    return 0;
}

void xcat(char *a,char *b)
{
    char *p1;
    char *p2;
    p1 = a;
    p2 = b;
    while(*p1)
    {
        p1++;
    }
    while(*p2)
    {
        *p1 = *p2;
        p1++;
        p2++;
    }
    *p1 = '\0';
    printf("The concatenated string is: %s\n",a);
}

void xcmp(char *a,char *b)
{
    int c,flag=0;
    while(*a&&*b)
    {
        if(*a!=*b)
        {
            flag = 1;
            c = *a-*b;
            break;
        }
    }
    if(flag==0)
        printf("0\n");
    else
        printf("%d\n",c);
}

void xreverse(char *a)
{
    int c=0;
    char *p1,*p2;
    char s[100];
    for(int i=1;a[i]!='\0';i++)
        c++;
    p1=a+c-1;
    p2=s;
    while(p1>=a)
    {
       *p2=*p1;
        p2++;
        p1--;
    }
    *p2='\0';
    printf("Original String: %s\n",a);
    printf("Reverse String: %s\n",s);
}