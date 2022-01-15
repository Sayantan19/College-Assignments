#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #include</home/doesitmatter/Desktop/College-Assignments/College 2nd Year/Day 6/Bringing them together.c>
#include"ABC2.c"

int main()
{
    int choice;
    do
    {
        printf("1 for GCD program\n2 for Linear Search program\n3 for Tower of Hanoi program\n4 for Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:     main2();
                        break;
            case 2:     main3();
                        break;
            case 3:     main1();
                        break;
            case 4:     return 0;
                        break;
            default:    printf("Wrong choice!\n");
        }
    }while(1);
    return 0;
}