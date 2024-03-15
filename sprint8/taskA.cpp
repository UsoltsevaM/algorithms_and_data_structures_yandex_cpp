#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::string line;
	std::getline(std::cin, line);

	std::vector<std::string> arr;
	std::string temp;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == ' ' && !temp.empty())
		{
			arr.push_back(temp);
			temp.clear();
			continue;
		}

		temp += line[i];
	}

	if (!temp.empty())
		arr.push_back(temp);

	for (auto it = arr.rbegin(); it != arr.rend(); it++)
		std::cout << *it << " ";
}