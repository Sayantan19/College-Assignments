#include <stdio.h>
void odd(int n)
{
    if (n & 1 == 1)
            printf("Odd\n");
        else
            printf("Even\n");
}
int main()
{
    int n;
    while (1)
    {
        printf("Enter the number\n");
        scanf("%d", &n);
        char ch[1];
        odd(n);
        printf("Do you want to continue y/n \n");
        scanf("%s",ch);
        if (ch == "y" || ch == "Y")
            continue;
        else if(ch=="n"|| ch=="N")
            return 0;
    }
    return 0;
}