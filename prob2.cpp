#include <iostream>

int main() {
	long long int back = 1, front = 2, temp = 0, i = 0;
	long long signed int sum = 0;
	while(back < 4000000) {
//		std::cout << back << std::endl;
		if(back % 2 == 0) {
			sum += back;
		}
		temp = front;
		front = back + front;
		back = temp;
	}
std::cout << sum << std::endl;
return 0;
}
