//Program to read a .txt file
#include <stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("note.txt", "r");
    char c;
    if (fp == NULL)
    {
        puts("Error while opening file");
        exit();
    }

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