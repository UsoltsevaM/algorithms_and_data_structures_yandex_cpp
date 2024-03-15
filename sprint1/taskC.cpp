#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n, m;
	std::cin >> n >> m;

	auto arr = std::vector<std::vector<int>>(n, std::vector<int>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> arr[i][j];

	int i, j;
	std::cin >> i >> j;

	std::vector<int> result;
	if (j + 1 < m)
		result.push_back(arr[i][j + 1]);
	if (j - 1 >= 0)
		result.push_back(arr[i][j - 1]);
	if (i + 1 < n)
		result.push_back(arr[i + 1][j]);
	if (i - 1 >= 0)
		result.push_back(arr[i - 1][j]);

	std::sort(result.begin(), result.end());
	for (const auto& item : result)
		std::cout << item << " ";

	return 0;
}