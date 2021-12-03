#include<stdio.h>
int factorial(int num)
{
  	int f=1;
  	for(int i=1;i<=num;i++)
		f = f*i;
    return f;
}

int combination(int n,int r)
{
	int c = factorial(n)/(factorial(r)*factorial(n-r));
	return c;
}

int main()
{
	int n,c=0;
	printf("Enter the number of rows \n");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=c+1;j<n;j++)
			printf(" ");
		for(int j=0;j<=c;j++)
		{
			printf("%d ",combination(c,j));
		}
		printf("\n");
		c++;
	}
	return 0;
}
			
	
