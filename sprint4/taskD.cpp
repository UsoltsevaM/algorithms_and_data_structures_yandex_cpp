#include <iostream>
#include <string>

int main()
{
	int a = 0;
	std::cin >> a;

	int m = 0;
	std::cin >> m;

	std::string str;
	std::cin >> str;

	int n = str.size();
	long long hash = 0;
	long long a_pow = 1;
	for (int i = 0; i < n; ++i)
	{
		hash += (static_cast<long long>(str[n - i - 1]) * a_pow) % m;
		hash = hash % m;
		a_pow *= a;
		a_pow = a_pow % m;
	}

	std::cout << hash;

	return 0;
}