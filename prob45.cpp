#include <iostream>
#include <math.h>

typedef long long unsigned int uint64;

// If its a hexagonal number, its also a triangle number (every other triangle number is also hexagonal)
bool isHex(uint64 num);
// Get n+1th pentagonal number
uint64 nextPent(uint64 n);


int main(void) {
  uint64 pent;
  for(uint64 i = 0;i <= 40758;++i) {
    pent = nextPent(i);
    if(isHex(pent)) {
      std::cout << pent << std::endl;
    }
  }
}

bool isHex(uint64 num) {
  double temp = (sqrt(8 * num + 1) + 1) / 4;
  if(floor(temp) == temp)
    return true;
  else
    return false;
}

uint64 nextPent(uint64 n) {
  n++;
  return n * (3 * n - 1) / 2;
}
