#include<iostream>
#include<vector>
using namespace std;
long long maxa(const vector<int>&numbers)
{
    long long max = 0;
    int n = numbers.size();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            if(((long long)numbers[i])*numbers[j]>max)
                max = ((long long)numbers[i])*numbers[j];
        }
    return max;
}

long long maxb(const vector<int>&numbers)
{
    long long max = 0;
    long long a=0,b=0;
    int pos,n;
    n = numbers.size();
    for(int i=0;i<n;i++)
    {
        if(numbers[i]>a)
        {
            a = numbers[i];
            pos=i;
        }
    }
    for(int j=0;j<n;j++)
    {
        if(numbers[j]>b&&j!=pos)
            b = numbers[j];
    }
    max = a*b;
    // cout<<a<<" "<<b<<"\n";
    return max;
}
int main()
{
    // while(true)
    // {
    //     int n = rand()%100+2;
    //     cout<<n<<"\n";
    //     vector<int>a;
    //     for(int i=0;i<n;i++)
    //         a.push_back(rand()%100000);
    //     for(int i=0;i<n;i++)
    //         cout<<a[i]<<" ";
    //     cout<<"\n";
    //     long long max1 = maxa(a);
    //     long long max2 = maxb(a);
    //     if(max1 != max2)
    //     {
    //         cout<<"Wrong answer: "<<max1<<" "<<max2<<"\n";
    //         break;
    //     }
    //     else
    //     cout<<"OK\n";
    // }
    int p,n;
    long long max1,max2;
    cin>>n;
    vector<int> numbers(n);
    for(int i=0;i<n;i++)
        cin>>numbers[i];
    // max1 = maxa(numbers);
    max2 = maxb(numbers);
    cout<<max2<<"\n";
}