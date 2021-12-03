#include<stdio.h>
int main()
{
	float pp,sp,d;
	int y;
	printf("Enter the purchase value \n");
	scanf("%f",&pp);
	printf("Enter the yearly depreciation amount \n");
	scanf("%f",&d);
	printf("Enter the number of years\n");
	scanf("%d",&y);
	sp = pp-(d*y);
	printf("The Salvage Value is %f\n",sp);
	return 0;
}
