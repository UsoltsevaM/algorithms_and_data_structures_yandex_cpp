#include <iostream>
#include <vector>
#include <string>

int main()
{
	int n;
	std::cin >> n;
	std::cin.ignore();

	std::string line;
	std::getline(std::cin, line);

	int length = 0;
	int maxLength = 0;
	int prevSpacePos = -1;
	std::string maxWord;
	for (int i = 0; i < n; ++i)
	{
		if (line[i] == ' ')
		{
			if (length > maxLength)
			{
				maxLength = length;
				maxWord = line.substr(prevSpacePos + 1, length);
			}
			length = 0;
			prevSpacePos = i;

			continue;
		}
		length++;
	}

	if (length > maxLength)
	{
		maxLength = length;
		maxWord = line.substr(prevSpacePos + 1, length);
	}

	std::cout << maxWord << std::endl;
	std::cout << maxLength << std::endl;

	return 0;
}