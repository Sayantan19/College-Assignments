#include<stdio.h>
int main()
{
	float c,f;
	printf("Enter temperature in celcius \n");
	scanf("%f",&c);
	f = ((9.0/5.0)*c)+32.0;
	printf("Temperature in fahrenheit is %f \n",f);
	return 0;
}
