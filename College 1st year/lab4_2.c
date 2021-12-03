#include <stdio.h>
#define maxsize 100 

int main()
{
    char str[maxsize];
    char * s = str;
    printf("Enter your text : ");
    gets(str);
    while(*s!='\0') 
    {
        *s = (*s >= 'a' && *s <= 'z') ? *s-32 : (*s>='A' && *s<='Z'?*s+32:*s);
        s++;
    }
    printf("\n%s\n",str);
    return 0;
}




