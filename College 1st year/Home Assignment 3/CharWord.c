#include <stdio.h>
#include <string.h>
 
void main()
{
    char s[200];
    int c=0,count = 0, i;
 
    printf("Enter the string:\n");
    scanf("%[^\n]s", s);
    for (i = 0;s[i] != '\0';i++)
    {
        if (s[i] == ' ' && s[i+1] != ' ')
            count++; 
        c++;   
    }
    printf("Number of words in given string are: %d\n", count + 1);
    printf("Number of characters in given string are: %d\n",c);
}