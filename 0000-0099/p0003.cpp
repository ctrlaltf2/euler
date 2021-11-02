#include <iostream> // cin, cout, endl
#include <map> // map
#include <math.h> // sqrt(), floor()
#include <vector> // vector, push_back()

using std::cin;
using std::cout;
using std::endl;
using std::map;

typedef long long unsigned int overkill;

bool isPrime(overkill num);
int nextPrime(overkill num);
std::vector<int> primeFactor(overkill num);

int main(void) {
  long unsigned int num;
  cout << "Enter number to test: ";
  cin >> num;
  std::vector<int> primes = primeFactor(num);
  cout << primes.back() << endl;
  return 0;
}

bool isPrime(overkill num) {
  if( (num == 1 ) || (num == 0) ) {
    return false;
  }
  if(num == 2)
    return true;
  else if(num % 2 == 0)
    return false;
  long unsigned int n_sqrtFloor = (long int) floor(sqrt(num));
  for(long unsigned int i = 3; i <= n_sqrtFloor; i += 2) {
    if(num % i == 0)
      return false;
  }
  return true;
}

int nextPrime(overkill num) {
  int i = num + 1;
  while(!isPrime(i)) {
    ++i;
  }
  return i;
}

// General implementation of prime factorization for later problems
std::vector<int> primeFactor(overkill num) {
  std::vector<int> vec;
  while(!isPrime(num)) {
    for(int i = 2;i <= floor(sqrt(num)); i = nextPrime(i)) {
      if(num % i == 0) {
        num /= i;
        vec.push_back(i);
        break;
      }
    }
  }
  vec.push_back(num);
  return vec;
}
