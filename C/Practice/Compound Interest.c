#include <stdio.h>
#include <conio.h>
#include<math.h>
int main()
{
    float p, r, t, ci, si;

    printf("Enter principal, rate of interes and time \n");
    scanf("%f%f%f", &p, &r, &t);

    si = p * r * t;
    ci = (p * ((float)pow((1.0 + r), t))) - p;

    printf("The compound interest is %f and the simple interest is %f \n", ci, si);
}