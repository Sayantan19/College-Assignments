#include<stdio.h>
int ceil(float a);

int main()
{
    float n;
    printf("Enter the number \n");
    scanf("%f",&n);
    printf("The required output is %f", (float)ceil(n));
    return 0;
}

int ceil(float a)
{
    if(a>0.0)
    return((int)a+1);
    else if(a<0.0)
    return((int)a);
}