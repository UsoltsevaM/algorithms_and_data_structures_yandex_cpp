#include <iostream>
#include <string>

int main()
{
	std::string subStr;
	std::string str;

	std::getline(std::cin, subStr);
	std::getline(std::cin, str);

	bool found = false;
	unsigned int j = 0;
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (j == subStr.size())
			break;

		if (subStr[j] == str[i])
			j++;
	}

	if (j == subStr.size())
		found = true;

	if (found)
		std::cout << "True";
	else
		std::cout << "False";

	return 0;
}