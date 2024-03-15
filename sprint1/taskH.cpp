#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::string strNum1;
	std::getline(std::cin, strNum1);

	std::string strNum2;
	std::getline(std::cin, strNum2);

	size_t maxLength = std::max(strNum1.size(), strNum2.size());

	std::vector<int> res;
	int carry = 0;
	for (size_t i = 0; i < maxLength; ++i)
	{
		int sum = carry;
		if (i < strNum1.size())
			sum += strNum1[strNum1.size() - 1 - i] - '0';
		if (i < strNum2.size())
			sum += strNum2[strNum2.size() - 1 - i] - '0';

		carry = (sum > 1) ? 1 : 0;
		res.push_back(sum % 2);
	}

	if (carry > 0)
		res.push_back(carry);

	for (auto it = res.rbegin(); it != res.rend(); ++it)
		std::cout << *it;

	return 0;
}
