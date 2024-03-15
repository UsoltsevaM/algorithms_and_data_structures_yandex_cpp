#include "solution.h"

#include <iostream>
#include <string>

/*
// Comment it before submitting
struct Node {
	Node(const std::string &value, Node* next, Node* prev)
		: value(value)
		, next(next)
		, prev(prev)
	{}
	std::string value;
	Node* next;
	Node* prev;
};*/

Node* insertInTail(Node** tail, Node* node)
{
	node->next = nullptr;
	node->prev = *tail;
	(*tail)->next = node;
	
	*tail = node;
	return *tail;
}

Node* solution(Node* head) {

	while (head->next)
		head = head->next;

	Node* newHead = head;
	Node* tail = head;
	Node* curNode = head->prev;

	while (curNode)
	{
		auto prev = curNode->prev;
		tail = insertInTail(&tail, curNode);
		curNode = prev;
	}

	newHead->prev = nullptr;
	return newHead;
}

void test() {
	Node node3("node3", nullptr, nullptr);
	Node node2("node2", nullptr, nullptr);
	Node node1("node1", nullptr, nullptr);
	Node node0("node0", nullptr, nullptr);
	node0.next = &node1;

	node1.next = &node2;
	node1.prev = &node0;

	node2.next = &node3;
	node2.prev = &node1;

	node3.prev = &node2;
	Node* new_head = solution(&node0);
	// result is : new_head == node3
	// node3->next == node2
	// node2->next == node1
	// node2->prev == node3
	// node1->next == node0
	// node1->prev == node2
	// node0->prev == node1
}

