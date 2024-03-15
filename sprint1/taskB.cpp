#include <iostream>
#include <vector>


int main()
{
	long long a, b, c;

	std::cin >> a >> b >> c;

	if ((std::abs(a % 2) == std::abs(b % 2)) &&
		(std::abs(b % 2) == std::abs(c % 2)))
		std::cout << "WIN";
	else
		std::cout << "FAIL";

	return 0;
}
