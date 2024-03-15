#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<int> ar1(n);
	for (int i = 0; i < n; i++)
		std::cin >> ar1[i];

	int m = 0;
	std::cin >> m;

	std::vector<int> ar2(m);
	for (int i = 0; i < m; i++)
		std::cin >> ar2[i];

	std::vector<int>& mainArr = n > m ? ar1 : ar2;
	std::vector<int>& arr = n > m ? ar2 : ar1;

	std::unordered_map<int, std::vector<int>> map1;
	for (int i = 0; i < mainArr.size(); i++)
	{
		auto it = map1.find(mainArr[i]);
		if (it != map1.end())
		{
			it->second.push_back(i);
		}
		else
		{
			map1.emplace(mainArr[i], std::vector{ i });
		}
	}

	int max = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		auto it = map1.find(arr[i]);
		if (it == map1.end())
		{
			continue;
		}
		else
		{
			auto positions = it->second;
			for (const auto& pos : positions)
			{
				int j = pos;
				int k = i;
				while ((k < arr.size() && j < mainArr.size()) && arr[k] == mainArr[j])
				{
					k++;
					j++;
				}
				max = (k - i) > max ? (k - i) : max;
			}
		}
	}

	std::cout << max;

	return 0;
}