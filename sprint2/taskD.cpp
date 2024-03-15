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

int solution(Node* head, const std::string& elem) 
{
	int i = 0;
	while (head)
	{
		if (head->value == elem)
			return i;

		head = head->next;
		i++;
	}

	return -1;
}

void test() {
	Node node3("node3", nullptr);
	Node node2("node2", &node3);
	Node node1("node1", &node2);
	Node node0("node0", &node1);
	int idx = solution(&node0, "node4");
	std::cout << idx;
	// result is : idx == 2
}
