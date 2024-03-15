#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>

bool greater(const std::pair<int, int>& val1, const std::pair<int, int>& val2)
{
	int invVal1 = -val1.first;
	int invVal2 = -val2.first;
	return std::tie(val1.second, invVal1) > std::tie(val2.second, invVal2);
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::unordered_map<int, int> idToNum;
	for (int i = 0; i < n; ++i)
	{
		int studentId = 0;
		std::cin >> studentId;

		auto it = idToNum.find(studentId);
		if (it == idToNum.end())
			idToNum.emplace(studentId, 1);
		else
			it->second++;
	}

	int k = 0;
	std::cin >> k;

	std::vector<std::pair<int, int>> idToNumVec(idToNum.begin(), idToNum.end());
	std::sort(idToNumVec.begin(), idToNumVec.end(), greater);

	for (int i = 0; i < k; ++i)
		std::cout << idToNumVec[i].first << " ";

	return 0;
}