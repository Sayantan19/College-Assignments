#include <stdio.h>
int main()
{
    FILE *fpr, *fpw;
    fpr = fopen("note.txt", "r");
    if (fpr == NULL)
    {
        puts("The file doesn't exist");
    }
    fpw = fopen("file2.txt", "w");
    char c;
    if (fpw == NULL)
    {
        puts("The file doesn't exist");
    }
    while (true)
    {
        c = fgetc(fpr);
        if (c == EOF)
            break;
        else
            fputc(c, fpw);
    }
    fclose(fpr);
    fclose(fpw);
    return 0;
}