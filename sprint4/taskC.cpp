#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
	std::string str1;
	std::string str2;
	std::getline(std::cin, str1);
	std::getline(std::cin, str2);

	if (str1.size() != str2.size())
	{
		std::cout << "NO";
		return 0;
	}

	std::unordered_map<char, char> map1;
	std::unordered_map<char, char> map2;
	for (unsigned int i = 0; i < str1.size(); i++)
	{
		auto it = map1.find(str2[i]);
		if (it == map1.end())
		{
			auto it = map2.find(str1[i]);
			if (it != map2.end())
			{
				std::cout << "NO";
				return 0;
			}

			map1.emplace(str2[i], str1[i]);
			map2.emplace(str1[i], str2[i]);
		}
		else
		{
			if (map1[str2[i]] != str1[i])
			{
				std::cout << "NO";
				return 0;
			}
		}

	}

	std::cout << "YES";

	return 0;
}