#include<stdio.h>
int main()
{
    int m;
    printf("Enter marks ");
    scanf("%d",&m);
    char g;
    g = (m>=90?'O':((m>=80&&m<=89)?'E':((m>=70&&m<=79)?'A':((m>=60&&m<=69)?'B':((m>=50&&m<=59)?'C':((m>=40&&m<=49)?'D':'F'))))));
    printf("Grade: %c\n",g);
    return 0;
}