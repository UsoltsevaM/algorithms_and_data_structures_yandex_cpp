#include <iostream>
#include <vector>
#include <string>

class MyQueueSized
{
private:
	struct Node {
		Node(int value, Node* next) : value(value), next(next) {}
		int value = 0;
		Node* next = nullptr;
	};

	Node* head = nullptr;
	Node* tail = nullptr;
	int curSize = 0;

public:
	void put(int val)
	{
		Node* node = new Node(val, nullptr);
		curSize++;

		if (!head)
		{
			head = node;
			tail = head;
			return;
		}
		tail->next = node;
		tail = node;
	}

	void get()
	{
		if (!head)
		{
			std::cout << "error" << std::endl;
			return;
		}
		std::cout << head->value << std::endl;
		
		Node* newHead = head->next;
		delete head;
		head = newHead;
		curSize--;
	}

	void size()
	{
		std::cout << curSize << std::endl;
	}
};

int main()
{
	int n = 0;
	std::cin >> n;

	MyQueueSized queue;

	std::string command;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> command;
		if (command == "put")
		{
			int arg = 0;
			std::cin >> arg;

			queue.put(arg);

			continue;
		}
		if (command == "get")
		{
			queue.get();
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