//This can calculate factorial for numbers as big as 100
#include<stdio.h>
int main()
{
    int i=0,j=0,fact[20000],k=0,l=1,n=0,temp=0; 
    fact[0]=1; 
    printf("enter value: "); 
    scanf("%d",&n); 
    for(i=2;i<=n;i++) 
    { 
        for(j=0;j<l;j++) 
        {
            k=temp+i*fact[j]; 
            fact[j]=k%10; 
            temp=k/10; 
        }    
        while(temp>0) 
        { 
            fact[l++]=temp%10; 
            temp=temp/10;       
        }           
    } 
    for(i=l-1;i>-1;i--) 
        printf("%d",fact[i]); 
    return 0;
}