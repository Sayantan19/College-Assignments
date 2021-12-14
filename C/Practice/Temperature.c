#include<stdio.h>
#include<conio.h>
int main()
{
    float celcius,fahrenheit;
    printf("Enter the temperature in Celcius \n");
    scanf("%f",&celcius);
    fahrenheit = ((celcius*9.0)/5.0)+32;
    printf("The temperature in Fahrenheit is %f \n",fahrenheit);
    return 0;
}