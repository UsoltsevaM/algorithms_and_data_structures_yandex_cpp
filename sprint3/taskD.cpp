#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<int> children(n);
	for (int i = 0; i < n; ++i)
		std::cin >> children[i];

	int m = 0;
	std::cin >> m;

	std::vector<int> cookies(m);
	for (int i = 0; i < m; ++i)
		std::cin >> cookies[i];

	std::sort(children.begin(), children.end(), std::greater<int>());
	std::sort(cookies.begin(), cookies.end(), std::greater<int>());

	int i = 0;
	int j = 0;
	int total = 0;
	while (i < n && j < m)
	{
		if (children[i] <= cookies[j])
		{
			total++;
			j++;
		}
		i++;
	}

	std::cout << total;

	return 0;
}