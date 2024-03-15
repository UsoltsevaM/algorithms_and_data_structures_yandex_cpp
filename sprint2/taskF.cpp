#include <iostream>
#include <stack>
#include <string>

class StackMax
{
private:
	std::stack<int> values;
	std::stack<int> maxValues;

public:
	void push(int val)
	{
		values.push(val);
		if (maxValues.empty())
		{
			maxValues.push(val);
			return;
		}

		if (val > maxValues.top())
		{
			maxValues.push(val);
			return;
		}
		
		maxValues.push(maxValues.top());
	}

	void pop()
	{
		if (values.empty())
		{
			std::cout << "error" << std::endl;
			return;
		}

		values.pop();
		maxValues.pop();
	}

	int getMax()
	{
		if (values.empty())
		{
			std::cout << "None" << std::endl;
			return -1;
		}

		std::cout << maxValues.top() << std::endl;
		return maxValues.top();
	}
};

int main()
{
	int n = 0;
	std::cin >> n; 
	
	StackMax stack;

	std::string command;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> command;
		if (command == "push")
		{
			int arg = 0;
			std::cin >> arg;

			stack.push(arg);

			continue;
		}
		if (command == "pop")
		{
			stack.pop();

			continue;
		}
		if (command == "get_max")
		{
			stack.getMax(); 

			continue;
		}
	}

	return 0;
}