#include <iostream>
#include <vector>
#include <string>
#include <cctype> 

bool isNotCharOrNum(const char& ch)
{
	return (!std::isalpha(ch) && !std::isdigit(ch));
}

int main()
{
	std::string line;
	std::getline(std::cin, line);

	size_t length = line.size();
	if (length == 0)
	{
		std::cout << "False";
		return 0;
	}

	bool isPalindrom = true;
	size_t i = 0;
	size_t j = length - 1;
	while (i < j)
	{
		while (isNotCharOrNum(line[i]))
			i++;
		while (isNotCharOrNum(line[j]))
			j--;

		if (i >= j)
			break;

		if (std::tolower(line[i]) != std::tolower(line[j]))
		{
			isPalindrom = false;
			break;
		}
		i++;
		j--;
	}

	if (isPalindrom)
		std::cout << "True";
	else
		std::cout << "False";

	return 0;
}
