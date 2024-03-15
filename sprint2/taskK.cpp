#include <iostream>

int fibonacci(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::cout << fibonacci(n);

	return 0;
}