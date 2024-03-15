/** Comment it before submitting
struct Node {
  int value;
  const Node* left = nullptr;
  const Node* right = nullptr;
};
**/

#include "solution_tree.h"
#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

const int INF = -1e9;

int Solution(const Node* root)
{
	if (root == nullptr)
		return INF;

	int curNode = root->value;
	int leftTree = Solution(root->left);
	int rightTree = Solution(root->right);
	if (leftTree > curNode)
		curNode = leftTree;
	if (rightTree > curNode)
		curNode = rightTree;

	return curNode;
}

void test() {
	Node node1({ 1, nullptr, nullptr });
	Node node2({ -5, nullptr, nullptr });
	Node node3({ 3, &node1, &node2 });
	Node node4({ 2, &node3, nullptr });
	assert(Solution(&node4) == 3);
}
