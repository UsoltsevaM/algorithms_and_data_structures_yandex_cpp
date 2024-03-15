#include <iostream>
#include <vector>

int main()
{
	int length;
	std::cin >> length;

	std::vector<int> num(length);
	for (int i = 0; i < length; ++i)
		std::cin >> num[i];

	int k;
	std::cin >> k;

	std::vector<int> res;
	int i = 0;
	int carry = 0;
	while (i < length || k > 0)
	{
		int sum = carry;
		if (i < length)
			sum += num[length - 1 - i];
		if (k > 0)
		{
			sum += k % 10;
			k = k / 10;
		}
		carry = (sum >= 10) ? 1 : 0;
		res.push_back(sum % 10);
		i++;
	}

	if (carry > 0)
		res.push_back(carry);

	for (auto it = res.rbegin(); it != res.rend(); it++)
		std::cout << *it << " ";

	return 0;
}
