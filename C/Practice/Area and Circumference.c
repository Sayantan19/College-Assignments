#include<stdio.h>
#include<conio.h>
int main()
{
    float radius;
    printf("Enter the Radius of the circle");
    scanf("%f",&radius);
    float area, circumference;
    area=3.142*radius*radius;
    circumference = 2*3.142*radius;
    printf("The Area of the circle is %f and the Circumference of the circle is %f \n",area,circumference);
    return 0;
}