#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int val, int left, int right)
{
	if (right <= left)
		if (left < arr.size() && arr[left] >= val)
			return left + 1;
		else
			return -1;

	int mid = (left + right) / 2;
	if (val <= arr[mid])
		return binarySearch(arr, val, left, mid);
	return binarySearch(arr, val, mid + 1, right);
}

int main()
{
	int daysNum = 0;
	std::cin >> daysNum;

	std::vector<int> sums;
	sums.resize(daysNum);
	for (int i = 0; i < daysNum; ++i)
		std::cin >> sums[i];

	int cycleCost = 0;
	std::cin >> cycleCost;

	int res1 = binarySearch(sums, cycleCost, 0, daysNum);
	int res2 = binarySearch(sums, 2 * cycleCost, 0, daysNum);

	std::cout << res1 << " " << res2;

	return 0;
}