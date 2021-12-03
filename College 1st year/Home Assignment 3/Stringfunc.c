#include<stdio.h>
void xstrncpy(char *,int,char *);
void xstrcat(char *, char *);
void xstrncat(char *,char *,int);
int xstrcmp(char *,char *);
void xstrtok(char *,char *);

int main()
{
    while(1)
    {
        int ch;
        printf("1 for strncpy\n2 for xstrcat\n3 for xstrncat\n4 for xstrcmp\n5 for xstrtok\nEnter your choice: ");
        scanf("%d",&ch);
        char str1[50],str2[50],src[50],dest[50],e[1];
        int n,c;
        switch(ch)
        {
            case 1:
            printf("Enter the source string: ");
            scanf("%s",src);
            printf("Enter the value of n: ");
            scanf("%d",&n);
            xstrncpy(src,n,dest);
            break;
            case 2:
            printf("Enter the 1st string: ");
            scanf("%s",str1);
            printf("Enter the 2nd string: ");
            scanf("%s",str2);
            xstrcat(str1, str2);
            printf("The Concatenated product is %s \n", str1);
            break;
            case 3:
            printf("Enter the 1st string: ");
            scanf("%s",str1);
            printf("Enter the 2nd string: ");
            scanf("%s",str2);
            printf("Enter the value of n: ");
            scanf("%d",&n);
            xstrncat(str1,str2,n);
            break;
            case 4:  
            printf("Enter the first string : ");  
            scanf("%s",str1);  
            printf("Enter the second string : ");  
            scanf("%s",str2);  
            c= xstrcmp(str1,str2); 
            printf("%d\n", c);
            break;
            case 5:
            printf("Enter the source string: ");
            scanf("%s",src);
            printf("Enter the split element: ");
            scanf("%s",e);
            xstrtok(src,e);
            break;
        }
        char t[1];
        printf("Do you want to continue? [y/n]: ");
        scanf("%s",t);
        if(xstrcmp(t,"n")==0)
            break;
    }
    return 0;
}

void xstrncpy(char *a,int n,char *b)
{
    for(int i=0;i<n;i++)
        b[i] = a[i];
    b[n] = '\0';
    printf("The Final string is: %s\n",b);
}

void xstrcat(char *a, char *b)
{
    int l,i;
    for(l=0;*(a+l)!='\0';l++);
    for(i=0;*(b+i)!='\0';i++)
        *(a+i+l)=*(b+i);
    *(a+l+i)='\0';
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

void xstrtok(char *a,char *c)
{
    int i=0;
    while(a[i]!='\0')
    {
        if(a[i]==c[0])
            printf("\n");
        else
            printf("%c",a[i]);
        i++;
    }
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
