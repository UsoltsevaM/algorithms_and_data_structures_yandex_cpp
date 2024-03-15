#include <iostream>
#include <vector>
#include <string>
#include <map>

int main()
{
	std::string str;
	std::cin >> str;

	int n = 0;
	std::cin >> n;

	std::map<int, std::string, std::greater<int>> posToSubst;

	int totalLength = 0;
	for (int i = 0; i < n; i++)
	{
		std::string subStr;
		std::cin >> subStr;

		int pos;
		std::cin >> pos;
		totalLength += subStr.size();

		posToSubst.emplace(pos, subStr);
	}

	int initialLength = str.size();
	str.resize(str.size() + totalLength);

	int currentFullLength = str.size();
	int currentLength = initialLength;
	for (const auto& it : posToSubst)
	{
		auto curPos = it.first;
		auto curSubstring = it.second;

		if (curPos > initialLength)
			continue;

		int offsetSize = currentLength - curPos;
		for (int i = 0; i < offsetSize; i++)
			str[currentFullLength - 1 - i] = str[currentLength - 1 - i];

		int idx = currentFullLength - 1 - offsetSize;
		for (int i = 0; i < curSubstring.size(); i++)
			str[currentFullLength - 1 - offsetSize - i] = curSubstring[curSubstring.size() - 1 - i];

		currentLength = curPos;
		currentFullLength = currentFullLength - curSubstring.size() - offsetSize;
	}

	std::cout << str;

	return 0;
}