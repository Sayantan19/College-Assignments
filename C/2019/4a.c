//Program to read a .txt file
#include <stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("C:\Users\SAYANTAN\Desktop\note.txt", "r");
    char c;
    while (true)
    {
        c = fgetc(fp);
        if (c == EOF)
            break;
        else
            printf("%c", c);
    }
    fclose(fp);
    return 0;
}