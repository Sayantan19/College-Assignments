#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fpr, *fpw;
    char file1[100], file2[100], c;
    printf("Enter the filename from which you wnat to copy contents \n");
    scanf("%s", file1);
    printf("Enter the name of the file to which you want to copy the contents to\n");
        scanf("%s", file2);
    fpr = fopen(file1, "r");
    fpw = fopen(file2,"w");
    if (fpr == NULL)
    {
        puts("File doesn't exist");
        exit(0);
    }
    if (fpw == NULL)
    {
        puts("File doesn't exist");
        exit(0);
    }
    while (true)
    {
        c = fgetc(fpr);
        if (c == EOF)
            break;
        else
            fputc(c, fpw);
    }
    printf("Contents copied successfully");
    fclose(fpr);
    fclose(fpw);
    return 0;
}