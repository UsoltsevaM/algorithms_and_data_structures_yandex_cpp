#include <iostream>
#include <cmath>

int fibonacci(int n, int mod)
{
	if (n == 1 || n == 0)
		return 1;

	int num1 = 1;
	int num2 = 1;
	int num3 = 0;
	for (int i = 1; i < n; i++) 
	{
		num3 = (num1 + num2) % mod;
		num1 = num2;
		num2 = num3;
	}
	return num3;
}

int main()
{
	int n = 0;
	int k = 0;
	std::cin >> n >> k;

   int mod = std::pow(10, k);

	std::cout << fibonacci(n, mod);

	return 0;
}