#include <iostream> // cin, cout, endl
#include <math.h> // sqrt(), floor()

#define kGoal 2000000

typedef long long unsigned int uint64;

bool isPrime(uint64 num);
uint64 nextPrime(uint64 num);

int main(void) {
  uint64 start = 17;
  uint64 temp = 7; // Where problem left off; Started at all primes below ten (2, 3, 5, 7) which equals 17
  while((temp = nextPrime(temp)), temp < kGoal) {
    start += temp;
  }
  std::cout << start << std::endl;
}

bool isPrime(uint64 num) {
  if(num % 2 == 0)
    return false;
  unsigned int n_sqrtFloor = (unsigned int) floor(sqrt(num));
  for(long unsigned int i = 3; i <= n_sqrtFloor; i += 2) {
    if(num % i == 0)
      return false;
  }
  return true;
}

uint64 nextPrime(uint64 num) {
  int i = num + 1;
  while(!isPrime(i)) {
    ++i;
  }
  return i;
}
