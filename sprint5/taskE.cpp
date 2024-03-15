﻿
/*
struct Node {
  int value;
  const Node* left = nullptr;
  const Node* right = nullptr;
};
*/

#include "solution_tree.h"
#include <cassert>
#include <vector>

using namespace std;


void BST(const Node* root, std::vector<int>& nodes)
{
    if (!root)
        return;
    BST(root->left, nodes);
    nodes.push_back(root->value);
    BST(root->right, nodes);
}

bool Solution(const Node* root)
{
    std::vector<int> nodes;
    BST(root, nodes);
    for (unsigned int i = 1; i < nodes.size(); i++)
        if (nodes[i] <= nodes[i - 1])
            return false;

    return true;
}

void test() {
    {
        Node node1({ 1, nullptr, nullptr });
        Node node2({ 4, nullptr, nullptr });
        Node node3({ 3, &node1, &node2 });
        Node node4({ 8, nullptr, nullptr });
        Node node5({ 5, &node3, &node4 });
        assert(Solution(&node5));
    }
    {
        Node node1({ 1, nullptr, nullptr });
        Node node2({ 5, nullptr, nullptr });
        Node node3({ 3, &node1, &node2 });
        Node node4({ 8, nullptr, nullptr });
        Node node5({ 5, &node3, &node4 });
        assert(!Solution(&node5));
    }
}
