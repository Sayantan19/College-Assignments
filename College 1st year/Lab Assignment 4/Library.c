#include<stdio.h>
#include<string.h>
struct book
{
    char name[20];
    char auth[20];
    char pub[20];
    int price;
    char branch[100];
}b[100];

int main()
{
    FILE *fp;
    int n;
    printf("Enter the number of books you want to make a record of: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the name of the book: ");
        scanf("%*c%[^\n]",b[i].name);
        printf("Enter the name of the author of the book: ");
        scanf("%*c%[^\n]",b[i].auth);
        printf("Enter the name of the publisher of the book: ");
        scanf("%*c%[^\n]",b[i].pub);
        printf("Enter the price of the book: ");
        scanf("%d",&b[i].price);
        printf("Enter the branch of the book: ");
        scanf("%*c%[^\n]",b[i].branch);
        printf("\n");
    }
    char p[20];
    printf("Enter the publisher name whose book list you want: ");
    scanf("%*c%[^\n]",p);
    printf("The books of the publisher are:\n");
    for(int i=0;i<n;i++)
    {
        if(strcmp(p,b[i].pub)==0)
        printf("%s\n",b[i].name);
    }
    char br[100];
    printf("Enter the name of the branch whose books you want to put in a file: ");
    scanf("%*c%[^\n]",br);
    fp = fopen("lib.txt","w");
    for(int i=0;i<n;i++)
    {
        if(strcmp(br,b[i].branch)==0)
        {
            fputs(b[i].name,fp);
            fputs("\n",fp);
        }
    }
    fclose(fp);
    printf("Names sent successfully\n");
    return 0;
}