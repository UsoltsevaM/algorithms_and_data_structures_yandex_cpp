#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

int main()
{
	std::string str;
	std::cin >> str;

	if (str.empty())
	{
		std::cout << "True";
		return 0;
	}

	std::unordered_map<char, char> bracketPairs = { {')', '('} ,{ '}', '{' } ,{ ']', '[' } };
	
	std::stack<char> brackets;
	for (size_t i = 0; i < str.size(); ++i)
	{
		char ch = str[i];
		if (ch == '(' || ch == '{' || ch == '[')
		{
			brackets.push(ch);
			continue;
		}
		if (ch == ')' || ch == '}' || ch == ']')
		{
			if (brackets.empty())
			{
				std::cout << "False";
				return 0;
			}

			if (brackets.top() == bracketPairs[ch])
			{
				brackets.pop();
				continue;
			}

			std::cout << "False";
			return 0;
		}
	}

	if (brackets.empty())
		std::cout << "True";
	else
		std::cout << "False";

	return 0;
}