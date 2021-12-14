#include <iostream>

int gcd_fast(int a, int b) {
  int c = a%b;
  if(c==0)
    return b;
  a = b;
  b = c;
  return gcd_fast(a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
