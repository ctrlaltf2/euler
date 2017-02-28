#include <iostream> // cin, cout, endl
#include <math.h> // sqrt()
#include <utility> // std::pair

#define kGoal 1000

typedef unsigned long int ulong;

using std::cout;
using std::cin;
using std::endl;

int gcd(int a, int b);
std::pair<ulong, ulong> decode(int m, int n);
std::pair<std::pair<ulong, ulong>, bool> isItTheOne(ulong a, ulong b);

// Uses euclid's formula to generate triplets to test
int main(void) {
  int m, n;
  std::pair<ulong, ulong> values;
  std::pair<  std::pair<ulong, ulong>, bool  > readabilityTM;
  // Generate every primitive
  for(m = 1;m < 100;++m) {
    for(n = 1;n < 100;++n) {
      if(m < n) break;
      if(m % 2 == 1 && n % 2 == 1) continue; // m and n can't both be odd
      if(gcd(m, n) != 1) continue; // If m and n aren't coprimes
      // It has passed all the tests, now to decode them into a, b, c
      values = decode(m, n);
      if(values.first > kGoal || values.second > kGoal) break;
      readabilityTM = isItTheOne(values.first, values.second);
      if(readabilityTM.second) {
        ulong c = sqrt( pow(readabilityTM.first.first, 2) + pow(readabilityTM.first.second, 2) );
        cout << "Found value! " << readabilityTM.first.first << " " << readabilityTM.first.second << " " << c << endl;
        return 0;
      }
    }
  }
}

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

std::pair<ulong, ulong> decode(int m, int n) {
  std::pair<ulong, ulong> values;
  values.first = (m * m) - (n * n);
  values.second = 2 * m * n;
  return values;
}

std::pair<std::pair<ulong, ulong>, bool> isItTheOne(ulong a, ulong b) {
  const ulong a_original = a;
  const ulong b_original = b;
  const ulong c_original = sqrt( (pow(a, 2) + pow(b, 2)) );
  std::pair<std::pair<ulong, ulong>, bool> rt;
  ulong a_test, b_test, c_test;
  int i = 2;
  do {
    a_test = a_original * i;
    b_test = b_original * i;
    c_test = c_original * i;
    cout << a_original << " " << b_original << " " << c_original << ": " << a_test << " " << b_test << " " << c_test << endl;
    if( (a_test + b_test + c_test) == kGoal) {
      rt.first.first = a_test;
      rt.first.second = b_test;
      rt.second = true;
      return rt;
    } else {
      ++i;
    }
  } while((a_test + b_test + c_test) < kGoal);
}

// References:
// http://www.tsm-resources.com/alists/trip.html - To confirm my primitive finder and find the pattern in how triplets derive from a primitive
// https://en.wikipedia.org/wiki/Pythagorean_triple#Generating_a_triple
