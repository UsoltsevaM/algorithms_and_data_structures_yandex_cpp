#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <cmath>


int numberOfPairsLessMid(const std::vector<int>& arr, int mid)
{
	int res = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		auto it1 = arr.begin() + i;
		auto it2 = arr.begin() + arr.size();
		res += std::upper_bound(it1, it2, arr[i] + mid) - (arr.begin() + i + 1);
	}
	return res;
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<int> areas(n);
	for (int i = 0; i < n; ++i)
		std::cin >> areas[i];

	int k = 0;
	std::cin >> k;

	std::sort(areas.begin(), areas.end());

	int low = areas[1] - areas[0];
	for (int i = 1; i < n - 1; ++i)
		low = std::min(low, areas[i + 1] - areas[i]);

	int high = areas[n - 1] - areas[0];
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (numberOfPairsLessMid(areas, mid) < k)
			low = mid + 1;
		else
			high = mid;
	}

	std::cout << low;

	return 0;
}