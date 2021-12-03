#include<stdio.h>
int main()
{
    char s[100];
    printf("Enter the string: ");
    gets(s);
    char *ptr;
    ptr = s;
    while(*ptr!='\0')
    {
        if(*ptr>=97&&*ptr<=122)
        {
            printf("%c",(*ptr-32));
        }
        else if(*ptr>=65&&*ptr<=90)
            printf("%c",(*ptr+32));
        else
            printf("%c",*ptr);
        ptr++;
    }
    printf("\n");
    return 0;
}