#include<stdio.h>
struct student
{
    char name[30];
    int roll_number;
    int marks;
}s[2], *ptr;
ptr = s;
int main()
{
    printf("%p\t%p",ptr,(
        ptr+1));  
}