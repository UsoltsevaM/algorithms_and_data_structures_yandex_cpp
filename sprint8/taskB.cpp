#include <iostream>
#include <vector>
#include <string>


int main()
{
	std::string str1;
	std::cin >> str1;

	std::string str2;
	std::cin >> str2;

	std::string& strMax = str2.size() > str1.size() ? str2 : str1;
	std::string& strMin = str1.size() < str2.size() ? str1 : str2;

	if (strMax.size() - strMin.size() > 1)
	{
		std::cout << "FAIL";
		return 0;
	}

	int counter = 0;
	for (int i = 0, j = 0; i < strMin.size(); j++)
	{
		if (strMax[j] != strMin[i])
		{
			if (++counter > 1)
				break;

			if (strMax.size() == strMin.size())
				i++;

			continue;
		}
		i++;
	}

	if (counter > 1)
	{
		std::cout << "FAIL";
		return 0;
	}

	std::cout << "OK";

	return 0;
}