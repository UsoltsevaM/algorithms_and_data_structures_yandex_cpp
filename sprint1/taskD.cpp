#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	auto temp = std::vector<int>(n);
	for (int i = 0; i < n; i++)
		std::cin >> temp[i];

	int daysInTotal = 0;
	for (int i = 0; i < n; i++)
	{
		int prev = (i - 1 >= 0) ? temp[i - 1] : -273;
		int next = (i + 1 < n) ? temp[i + 1] : -273;
		if ((temp[i] > prev) && (temp[i] > next))
			daysInTotal++;
	}

	std::cout << daysInTotal;

	return 0;
}