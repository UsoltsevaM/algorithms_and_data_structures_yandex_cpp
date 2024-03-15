#include <vector>
#include <cassert>
#include <iostream>

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];

	std::vector<int> colors(3);
	for (int i = 0; i < n; ++i)
		colors[arr[i]]++;

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < colors[i]; j++)
			std::cout << i << " ";

	return 0;
}