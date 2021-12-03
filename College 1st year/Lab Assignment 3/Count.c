#include <stdio.h>
#include<string.h>
int main()
{
    int blank, tab, new;
    blank = 0;
    tab = 0;
    new = 0;
    char c[100];
    printf("Input text (press D to end)\n");
    scanf("%[^D]s",c);
    for(int i=0;i<strlen(c);i++)
    {
        if ( c[i] == ' ' ){
        ++blank;
        }
        if ( c[i] == '\t' ){
        ++tab;
        printf("\\t");
        }
        if ( c[i] == '\n' ){
        ++new;
        printf("\\n");
        }
        else
        printf("%c",c[i]);
    }  
    printf("\n");
    printf("blank=%d,\ntab=%d,\nnewline=%d\n",blank,tab,new);
    return 0;
}
