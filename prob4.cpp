#include <iostream>
#include <cmath>
#include <string>

int digits(long long int num) {
	int a = floor(log10(num)) + 1;
	return a;
}

bool isPal(int num) {
	int a, b;
	int d = digits(num);
	b = d - 1;
	a = 0;
	std::string testCase = std::to_string(num);
	if(d % 2 == 1) { //odd
		int mid = ceil(d/2) + 2;
		for(;a != mid;a++) {
			if(a == mid)
				return true;
			if(testCase[a] != testCase[b])
				return false;
			b--;
		}
	} else if (d % 2 == 0) { //even
		for(;;a++) {
			if(b - a == 1 && testCase[a] == testCase[b])
				return true;
			if(testCase[a] != testCase[b])
				return false;
			b--;
		}
	}
}
int main() {
	int a = 999, b = 999, c = 0, offset = 0, cur = 0;
	while(a >=100) {
		while(b >= 100) {
			c = a * b;
			if(isPal(c)) {
				if(c > cur) {
					cur = c;
				}
			}
			b--;
		}
	a--;
	offset++;
	b = 999 - offset + 1;
	}
	std::cout << cur << std::endl;
}
