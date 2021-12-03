#include<stdio.h>
void xstrncat(char *,char *,int);
int main()
{
    char str1[50],str2[50];
    int n;
    printf("Enter the 1st string: ");
    gets(str1);
    printf("Enter the 2nd string: ");
    gets(str2);
    printf("Enter the value of n: ");
    scanf("%d",&n);
    xstrncat(str1,str2,n);
    return 0;
}

int xstrlen(char *a)
{
    int s;
    for (s = 0; *(s + a) != 0; s++)
        ;
    return s;
}

void xstrncat(char *a,char *b,int n)
{
    int x=0;
    int l = xstrlen(a);
    char c[n+l+1];
    for(int i=0;i<l;i++)
        c[i] = a[i];
    for(int i=l;i<(n+l);i++)
    {
        c[i] = b[x];
        x++;
    }
    b[n+l+1] = '\0';
    printf("The Final string is: %s\n",c);
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

