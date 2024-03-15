#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<int> sides(n);
	for (int i = 0; i < n; ++i)
		std::cin >> sides[i];

	std::sort(sides.begin(), sides.end(), std::greater<int>());

	for (int i = 0; i < n - 2; ++i)
	{
		if (sides[i] < sides[i + 1] + sides[i + 2])
		{
			std::cout << (sides[i] + sides[i + 1] + sides[i + 2]);
			return 0;
		}
	}

	return 0;
}