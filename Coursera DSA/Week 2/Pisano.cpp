#include<bits/stdc++.h>
using namespace std;
// //Program to be divided into 3 parts:
// 1. Find the pisano period for that number
// 2. Find the Fn and mod it
// 3. use the driver function to call both

long long Pisano(long long n)
{
    long long a=0,b=1,c,s=0;
    while(true)
    {
        c=(a+b)%n;
        a=b;
        b=c;
        if(a==0&&b==1)
            return s+1;
        s++;
    }
    return 0;
}

long long Fibo(long long n,long long m)
{
    long long pisano = Pisano(m);
    n = n%pisano;
    int a=0,b=1;
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    long long c;
    for(int i=0;i<n-1;i++)
    {
        c=(a+b)%m;
        a=b;
        b=c;
    }
    return c%m;
}

int main()
{
    long long n,m;
    cin>>n>>m;
    cout<<Fibo(n,m);
}