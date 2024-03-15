#include <iostream>
#include <string>
#include <unordered_map>

struct Data
{
	Data(int min, int max, int delta) : min(min), max(max), delta(delta) {}
	int max = 0;
	int min = 0;
	int delta = 0;
};

int main()
{
	int n = 0;
	std::cin >> n;

	std::unordered_map<int, Data> map;
	int sum = 0;

	map.emplace(0, Data(0, 0, 0));
	for (int i = 1; i <= n; i++)
	{
		int num = 0;
		std::cin >> num;

		if (num == 0)
			sum -= 1;
		else
			sum += 1;

		auto it = map.find(sum);
		if (map.find(sum) != map.end())
		{
			if (i < it->second.min)
				it->second.min = i;

			if (i > it->second.max)
				it->second.max = i;

			it->second.delta = it->second.max - it->second.min;
		}
		else
		{
			map.emplace(sum, Data(i, i, 0));
		}
	}

	int max = 0;
	for (auto& it : map)
		if (it.second.delta > max)
			max = it.second.delta;

	std::cout << max;

	return 0;
}