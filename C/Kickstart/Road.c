#include<stdio.h>
int dist(char a[],int n)
{
    int s=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!='1')
            s=s+1;
        else
            return s;
    }
}

int house(char s[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            int c=0;
            char s1[i],s2[n-i];
            for(int j=i;j>0;j--)
            {
                s1[c] = s[j];
                c++;
            }
            int d1,d2;
            d1=dist(s1,(c+1));
            c=0;    
            for(int j=i;j<=n;j++)
            {
                s2[c] = s[j];
                c++;
            }
            d2=dist(s2,(c+1));
            if(d2>d1)
                sum+= d1;
            else
                sum+= d2;
        }
            // sum=sum+1;
    }
    return sum;
}

int main()
{
    int t,n;
    //number of test cases
    scanf("%d",&t);
    int output[t];
    for(int i=0;i<t;i++)
    {
        //number of houses
        scanf("%d",&n);
        char s[n];
        scanf("%s",s);
        output[i]=house(s,n);
    }
    for(int i=0;i<t;i++)
    {
        printf("Case #%d: %d",(i+1),output[i]);
        printf("\n");
    }
    return 0;
}