#include <stdio.h>

int factOf(int num){
    int fact = 1;
    for(int i=1;i<=num;i++)
        fact= fact * i;
    return fact;
}

int main() {
	int n;
	printf("Find factorial of \n");
	scanf("%d",&n);
	printf("\nThe factorial of %d is %d",n,factOf(n));
	return 0;
}