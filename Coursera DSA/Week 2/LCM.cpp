#include<iostream>
using namespace std;

int gcd_fast(int a, int b) {
  int c = a%b;
  if(c==0)
    return b;
  a = b;
  b = c;
  return gcd_fast(a,b);
}

long long lcm_fast(int a,int b)
{
    long long lcm = ((long long)a*b)/gcd_fast(a,b);
    return lcm;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<lcm_fast(a,b)<<endl;
    return 0;
}