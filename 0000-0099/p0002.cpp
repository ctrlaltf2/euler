#include <iostream>

typedef long long unsigned int uint64;


// 	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987

int sum = 0;

int main(void) {
  uint64 back = 1, front = 1, a;
  for(int i = 3;i <= 5000;++i) {
    a = front;
    front = back + front;
    back = a;
    if(back > 4000000)
      break;
    if(back % 2 == 0)
      sum += back;
  }
  std::cout << sum << std::endl;
}
