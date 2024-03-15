#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
	int n = 0;
	int money = 0;
	std::cin >> n >> money;

	std::vector<int> houses(n);
	for (int i = 0; i < n; ++i)
		std::cin >> houses[i];

	std::sort(houses.begin(), houses.end());

	int sum = 0;
	int i = 0;
	int total = 0;
	while (sum < money && i < n)
	{
		sum += houses[i++];
		total++;
	}

	if (sum > money)
		total--;

	std::cout << total;

	return 0;
}