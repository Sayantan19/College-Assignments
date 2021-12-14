#include <stdio.h>
#include <math.h>
#include <string.h>
int Encrypt(char[], int);
int main()
{
    char s[81];
    scanf("%s", s);
    // scanf("\n");
    int l = strlen(s);
    Encrypt(s, l);
    return 0;
}
int Encrypt(char s[], int l)
{
    int c = ceil(sqrt(l));
    int r = floor(sqrt(l));
    // if((r*c)<l)
    // {
    //     r++;
    // }
    char m[r][c];
    int k = 0;
    s[l+1]='\0';
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            m[i][j] = s[k];
            k++;
        }
    }
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
            printf("%c", m[j][i]);
        printf(" ");
    }
    return 0;
}