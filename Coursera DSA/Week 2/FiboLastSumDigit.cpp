#include<iostream>
using namespace std;

int Fibo(long long n)
{
    int a=0,b=1,c;
    long sum = 0;
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    for(long long i=0;i<n;i++)
    {
        c = a+b;
        a = b;
        sum += b;
        b = c;
    }
    return (sum%10);
}

int main()
{
    long long n;
    cin>>n;
    cout<<(Fibo(n));
}