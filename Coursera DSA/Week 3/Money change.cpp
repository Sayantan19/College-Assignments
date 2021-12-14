#include<bits/stdc++.h>
using namespace std;

int Money(int n)
{
    int a[] = {10,5,1};
    int i=0,sum=0;
    while(true)
    {
        if(n-a[i]>=0)
        {
            n-=a[i];
            sum++;
        }
        else if(n-a[i]!=0&&n>0)
            i++;
        else if(n==0)
            return sum;
    }
}

int main()
{
    int m;
    cin>>m;
    cout<<Money(m);
}