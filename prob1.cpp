#include <iostream>

int main()
{
	int i, sum, bound;
	sum = 0;
	std::cout << "What number to test to ";
	std::cin >> bound;
	for(i = 1;i < bound;i++)
	{
		if(i % 3 == 0)
			sum += i;
		else if(i % 5 == 0)
			sum += i;
	}
	std::cout << std::endl << sum << std::endl;
	return 0;
}
