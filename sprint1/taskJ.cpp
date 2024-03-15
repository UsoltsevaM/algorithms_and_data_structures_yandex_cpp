#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int i = 2;
	while (i * i <= n)
	{
		while (n % i == 0)
		{
			std::cout << i << " ";
			n = n / i;
		}
		i++;
	}

	if (n != 1)
		std::cout << n << " ";

	return 0;
}
