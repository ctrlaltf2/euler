#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

long long unsigned int fac(long long unsigned int num);
long long unsigned int ncr(int n, int r);

int main(void) {
  int num{0};
  cout << "Enter a grid size: ";
  while(true) {
    if(!(cin >> num) || num <= 0) {
      cin.clear();
      cin.ignore(1234, '\n');
      cout << "Enter a valid integer: ";
      num = 0;
      continue;
    }
    break;
  }
  cout << ncr(num * 2, num) << endl;
  return 0;
}

long long unsigned int fac(long long unsigned int c) {
  if(c > 1) {
    return c * fac(c - 1);
  } else {
    return 1;
  }
}

// I don't want to install gmp
long long unsigned int ncr(int n, int r) {
  long long unsigned int res = fac(n) / fac(r) / fac(n - r);
  return res;
}
