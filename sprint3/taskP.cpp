#include <iostream>
#include <vector>
#include <algorithm>

int maxPartitions(const std::vector<int> arr)
{
	int parts = 0;
	int currentMax = 0;
	for (unsigned int i = 0; i < arr.size(); ++i)
	{
		currentMax = std::max(currentMax, arr[i]);
		if (currentMax == i)
			parts++;
	}
	return parts;
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];

	std::cout << maxPartitions(arr);
	return 0;
}