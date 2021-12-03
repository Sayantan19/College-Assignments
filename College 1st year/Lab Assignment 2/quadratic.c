#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c;
	printf("Enter the coefficients \n");
	scanf("%f",&a);
	scanf("%f",&b);
	scanf("%f",&c);
	float det = pow(b,2) - 4*a*c;
	if(det>0.0)
	{
		float r1 = (-b + sqrt(det))/(2.0*a);
		float r2 = (-b - sqrt(det))/(2.0*a);
		printf("Root 1 = %0.2f\nRoot 2 = %0.2f\n",r1,r2);
	}
	else if(det == 0.0)
	{
		float r = -b/(2.0*a);
		float r3 = b/(2.0*a);
		printf("Root is %0.2f and %0.2f\n",r,r3);
	}
	else if(det<0.0)
	{
		float real = -b/(2.0*a);
		float img = sqrt(-det)/(2.0*a);
		printf("Root is %0.2f + %0.2fi\n",real,img);
	}
	return 0;
}
	
