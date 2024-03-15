#include <iostream>
#include <vector>

int findPattern(const std::vector<int>& str, const std::vector<int>& pattern, int start)
{
	if (str.size() < pattern.size())
		return -1;

	for (int pos = start; pos <= str.size() - pattern.size(); pos++)
	{
		bool match = true;
		int shift = str[pos] - pattern[0];
		for (int offset = 0; offset < pattern.size(); offset++)
		{
			if (str[pos + offset] - pattern[offset] != shift)
			{
				match = false;
				break;
			}
		}
		if (match)
			return pos;
	}

	return -1;
}

std::vector<int> findAllPatterns(const std::vector<int>& str, const std::vector<int>& pattern)
{
	auto res = std::vector<int>{};

	int start = 0;
	for (;;)
	{
		int pos = findPattern(str, pattern, start);
		if (pos < 0)
			break;

		res.push_back(pos);
		start = pos + 1;
	}

	return res;
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<int> str(n);
	for (int i = 0; i < n; i++)
		std::cin >> str[i];

	int m = 0;
	std::cin >> m;

	std::vector<int> pattern(m);
	for (int i = 0; i < m; i++)
		std::cin >> pattern[i];

	auto positions = findAllPatterns(str, pattern);
	for (const auto& pos : positions)
		std::cout << pos + 1 << " ";

	return 0;
}