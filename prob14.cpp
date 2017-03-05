#include <iostream> // cout, endl
#include <unordered_map> // unordered_map

typedef unsigned long long int uint64;

void collatz(std::unordered_map<uint64, int>& M, uint64 num, int& original);

int main(void) {
  std::unordered_map<uint64, int> hopmap; // number in sequence and number of hops it took
  int temp = 0, maxhops = 0, finalnumber = 0;
  for(int i = 2; i < 1000000; ++i) {
    collatz(hopmap, i, i);
    temp = hopmap[i];
    if(temp > maxhops) {
      maxhops = temp;
      finalnumber = i;
    }
  }
  std::cout << finalnumber << " with " << maxhops << " hops." << std::endl;
}

void collatz(std::unordered_map<uint64, int>& M, uint64 num, int& original) {
  if(M[num]) {
    M[original] += M[num];
    return;
  } else if(num != 1) {
    if(num % 2 == 0) {
      num = (num / 2);
    } else {
      num = (num * 3) + 1;
    }
    M[original] += 1;
    collatz(M, num, original);
  } else {
    ++M[original];
  }

}
