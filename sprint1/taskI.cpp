#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int remainder = 0;
	while (n >= 4)
	{
		remainder = n % 4;
		if (remainder != 0)
			break;

		n = n / 4;
	}

	if (n == 1 && remainder == 0)
		std::cout << "True";
	else
		std::cout << "False";

	return 0;
}