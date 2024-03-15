#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::getline(std::cin, s);

	std::string t;
	std::getline(std::cin, t);

	int arr[128] = { 0 };

	for (const auto& ch : t)
		arr[ch]++;


	for (const auto& ch : s)
		arr[ch]--;


	for (int i = 0; i < 128; i++)
		if (arr[i] > 0)
		{
			std::cout << (char)i;
			break;
		}

	return 0;
}
