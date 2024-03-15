#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

bool comp(std::pair<std::string, int> lhs, std::pair<std::string, int> rhs)
{
	return lhs.second < rhs.second;
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::cin.ignore();
	std::unordered_map<std::string, int> items;
	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::getline(std::cin, str);
		if (items.find(str) == items.end())
			items.emplace(str, i);
	}

	std::vector<std::pair<std::string, int>> itemsVec(items.begin(), items.end());
	std::sort(itemsVec.begin(), itemsVec.end(), comp);

	for (const auto& it : itemsVec)
		std::cout << it.first << std::endl;

	return 0;
}