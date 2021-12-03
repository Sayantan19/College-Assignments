#include <stdio.h>  
int xstrcmp(char *,char *);  
int main()  
{  
    char str1[20];  
    char str2[20];  
    printf("Enter the first string : ");  
    scanf("%s",str1);  
    printf("Enter the second string : ");  
    scanf("%s",str2);  
    int c= xstrcmp(str1,str2); 
    printf("%d\n", c);
    return 0;  
}  
    
int xstrcmp(char *a,char *b)  
{  
    int flag=0,i=0;  
    while(a[i]!='\0' &&b[i]!='\0')
    {  
       if(a[i]!=b[i])  
       {  
           return (a[i]-b[i]);
           break;    
       }  
       i++;  
    }  
    if(flag==0)  
    return 0;  
}  