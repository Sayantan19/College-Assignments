#include<stdio.h>
int main()
{
    int marks;
    printf("Enter the marks out of 100 \n");
    scanf("%d",&marks);
    if (marks>=90)
        printf("O\n");
    else if (marks>=80&&marks<=89)
        printf("E\n");
    else if (marks>=70&&marks<=79)
        printf("A\n");
    else if (marks>=60&&marks<=69)
        printf("B\n");
    else if (marks>=50&&marks<=59)
        printf("C\n");
    else if (marks>=40&&marks<=49)
        printf("D\n");        
    else
        printf("F\n");    
    return 0;;
}