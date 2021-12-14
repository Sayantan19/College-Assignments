/*WAP that accepts the marks of 5 subjects and finds the sum and percentage marks obtained by the student.*/
#include <stdio.h>
#include <conio.h>
int main()
{
    float mark1, mark2, mark3, mark4, mark5;
    printf("Enter the marks obtained in 5 subjects out of 100 \n");
    scanf("%f %f %f %f ", &mark1, &mark2, &mark3, &mark4, &mark5);
    float sum, percent;
    sum = mark1 + mark2 + mark3 + mark4 + mark5;
    percent = (sum / 500.0)*100;
    printf("You have achieved %f marks out of 500 and your percentage is %f \n", sum, percent);
    return 0;
}