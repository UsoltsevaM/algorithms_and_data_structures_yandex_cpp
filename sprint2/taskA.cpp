#include <iostream>
#include <vector>

int main()
{
	unsigned int n;
	std::cin >> n;

	unsigned int m;
	std::cin >> m;

	std::vector<std::vector<int>> arr = { m, std::vector<int>(n) };

	for (unsigned int i = 0; i < n; ++i)
		for (unsigned int j = 0; j < m; ++j)
		{
			std::cin >> arr[j][i];
		}

	for (unsigned int i = 0; i < m; ++i)
	{
		for (unsigned int j = 0; j < n; ++j)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}