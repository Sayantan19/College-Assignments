#include <iostream>
using namespace std;
int sum_of_two_digits(int first_digit, int second_digit) {
    return first_digit + second_digit;
}
int main()
{
    int a,b;
    cin>>a;
    cin>>b;
    int sum = sum_of_two_digits(a,b);
    cout<<sum;
}