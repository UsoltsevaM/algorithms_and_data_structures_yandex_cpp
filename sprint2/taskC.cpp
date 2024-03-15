#include "solution.h"

#include <iostream>
#include <string>

/*
struct Node {
	std::string value;
	Node* next;
	Node(const std::string &value, Node* next) : value(value), next(next) {};
};
*/

Node* solution(Node* head, int idx)
{
	if (!head)
		return nullptr;

	if (idx == 0)
	{
		head = head->next;
		return head;
	}

	auto curNode = head;
	for (int i = 0; i < idx - 1; i++)
	{
		if (!curNode)
			return head;

		curNode = curNode->next;
	}

	if (!curNode->next)
		return head;

	curNode->next = curNode->next->next;

	return head;
}

void test() {
	Node node3("node3", nullptr);
	Node node2("node2", &node3);
	Node node1("node1", &node2);
	Node node0("node0", &node1);
	Node* new_head = solution(&node0, 5);

	while (new_head)
	{
		std::cout << new_head->value << " ";
		new_head = new_head->next;
	}
}
