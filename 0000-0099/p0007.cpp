#include <iostream>
#include <cmath>

bool isPrime(long int num) {
	if((num % 2 == 0)) {
		return false;
	} else {
		int max, i;
		max = ceil(sqrt(num)) + 2;
		for(i = 3;i < max; i++) {
			if(num % i == 0)
				return false;
		}
		return true;
	}
}


int main() {
	int cur = 2;
	long int i;
	for(i = 3;;i += 2) {
		if(isPrime(i)) {
			cur++;
		}
		if(cur == 10001)
			break;
	}
	std::cout << i << std::endl;
	return 0;
}
