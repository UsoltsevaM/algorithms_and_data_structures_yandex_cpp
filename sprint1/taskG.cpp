#include <iostream>
#include <stack>

int main()
{
	int n;
	std::cin >> n;

	std::stack<int> res;
	while (n > 0)
	{
		res.push(n % 2);
		n = n / 2;
	}

	while (!res.empty())
	{
		std::cout << res.top();
		res.pop();
	}

	return 0;
}
