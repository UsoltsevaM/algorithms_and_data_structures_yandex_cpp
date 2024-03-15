#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool greater1(const std::string& a, const std::string& b)
{
	if (a.size() == b.size())
		return a > b;

	const std::string sMax = a.size() > b.size() ? a : b;
	const std::string sMin = a.size() < b.size() ? a : b;

	for (unsigned int i = 0, j = 0; i < sMax.size(); ++i)
	{
		char c1 = (i >= sMin.size()) ? sMax[j++] : sMin[i];
		char c2 = sMax[i];

		if (c1 != c2)
			return c1 > c2 ? sMin == a : sMax == a;
	}

	return false;
}

bool greater(const std::string& a, const std::string& b)
{
	if (a.size() == b.size())
		return a > b;

	for (unsigned int i = 0, j1 = 0, j2 = 0; i < a.size() + b.size(); ++i)
	{
		char c1 = (i >= a.size()) ? b[j1++] : a[i];
		char c2 = (i >= b.size()) ? a[j2++] : b[i];

		if (c1 != c2)
			return c1 > c2;
	}

	return false;
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<std::string> arr;
	arr.resize(n);
	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];

	std::sort(arr.begin(), arr.end(), greater);

	for (int i = 0; i < n; ++i)
		std::cout << arr[i];

	return 0;
}