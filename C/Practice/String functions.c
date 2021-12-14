#include <stdio.h>

int xstrlen(char *);
void xstrcat(char *, char *);
void xstrcpy(char *, char *);

int main()
{
    char str1[50], str2[50];
    gets(str1);
    gets(str2);
    printf("The length of the strings are %d %d \n", xstrlen(str1), xstrlen(str2));
    // xstrcat(str1, str2);
    // printf("The Concatenated product is %s \n", str1);
    xstrcpy(str2,str1);
    printf("The Copied string is %s\n",str1);
    return 0;
}

int xstrlen(char *a)
{
    int s;
    for (s = 0; *(s + a) != 0; s++)
        ;
    return s;
}

void xstrcat(char *a, char *b)
{
    int l,i;
    for(l=0;*(a+l)!='\0';l++);
    for(i=0;*(b+i)!='\0';i++)
        *(a+i+l)=*(b+i);
    *(a+l+i)='\0';
}

void xstrcpy(char *a,char *b)
{
    int l;
    for(l=0;*(a+l)!=0;l++)
        *(b+l)=*(a+l);
    *(b+l)='\0';
}