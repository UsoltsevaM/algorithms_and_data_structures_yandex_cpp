#include <iostream>
#include <vector>
#include <string>

class MyQueueSized
{
private:
	std::vector<int> myQueue;
	int head = 0;
	int tail = 0;
	int curSize = 0;
	int maxSize = 0;

public:
	MyQueueSized(int maxSize) : maxSize(maxSize) 
	{
		myQueue.resize(maxSize);
	};

	void push(int val)
	{
		if (curSize == myQueue.size())
		{
			std::cout << "error" << std::endl;
			return;
		}
		myQueue[tail] = val;
		tail = (tail + 1) % maxSize;
		curSize++;
	}

	void pop()
	{
		if (curSize == 0)
		{
			std::cout << "None" << std::endl;
			return;
		}

		std::cout << myQueue[head] << std::endl;
		head = (head + 1) % maxSize;
		curSize--;
	}

	int peek()
	{
		if (curSize == 0)
		{
			std::cout << "None" << std::endl;
			return -1;
		}
		std::cout << myQueue[head] << std::endl;
		return myQueue[head];
	}

	int size()
	{
		std::cout << curSize << std::endl;
		return curSize;
	}
};

int main()
{
	int n = 0;
	std::cin >> n;

	int maxSize = 0;
	std::cin >> maxSize;

	MyQueueSized queue(maxSize);

	std::string command;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> command;
		if (command == "push")
		{
			int arg = 0;
			std::cin >> arg;

			queue.push(arg);

			continue;
		}
		if (command == "pop")
		{
			queue.pop();
			continue;
		}
		if (command == "peek")
		{
			queue.peek();
			continue;
		}

		if (command == "size")
		{
			queue.size();
			continue;
		}
	}

	return 0;
}