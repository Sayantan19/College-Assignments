#include<stdio.h>

void Dec2Hex(int n)
{
    int hex=0;
    if(!n)
        return;
    else {
        hex=n%16;
        Dec2Hex(n/16);
    }
    if(hex>9)
        printf("%c",'A'+(hex-10));
    else
        printf("%d",hex);
}

int main()
{
    int k=0;
    printf("Enter no:");
    scanf("%d",&k);
    Dec2Hex(k);
    printf("\n");
    return 0;
}