#include <iostream>
#include <string>
#include <vector>

int main()
{
	int a = 0;
	std::cin >> a;

	int m = 0;
	std::cin >> m;

	std::string str;
	std::cin >> str;

	int n = str.size();
	std::vector<long long> hashes(n);
	std::vector<long long> pows(n);

	long long hash = 0;
	long long a_pow = 1;
	for (int i = 0; i < n; ++i)
	{
		hash = (a * hash + static_cast<long long>(str[i])) % m;
		hashes[i] = hash;

		pows[i] = a_pow;
		a_pow *= a;
		a_pow = a_pow % m;
	}

	int num = 0;
	std::cin >> num;

	for (int j = 0; j < num; ++j)
	{
		int l = 0;
		int r = 0;
		std::cin >> l;
		std::cin >> r;

		long long leftHash = 0;
		if (l - 2 >= 0)
			leftHash = hashes[l - 2];

		long long pow = 0;
		if (r - l + 1 < n)
			pow = pows[r - l + 1];

		long long resultHash = (hashes[r - 1] - pow * leftHash) % m;
		if (resultHash < 0)
			resultHash += m;

		std::cout << resultHash << std::endl;
	}


	return 0;
}