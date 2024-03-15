#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main()
{
	std::string str;
	std::cin >> str;

	int maxLength = 0;
	std::unordered_map<char, int> map;
	int leftBound = 0;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		char ch = str[i];
		auto it = map.find(ch);
		if (it == map.end())
		{
			map.emplace(ch, i);
		}
		else
		{
			if (it->second >= leftBound)
			{
				int length = i - leftBound;
				if (length > maxLength)
					maxLength = length;

				leftBound = it->second + 1;
			}
			it->second = i;
		}
	}

	int delta = str.size() - leftBound;
	if (maxLength < delta)
		maxLength = delta;

	std::cout << maxLength;

	return 0;
}