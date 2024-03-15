﻿/*struct Node {
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
};*/


#include "solution_tree.h"
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

int inOrderTraversal(const Node* root)
{
    if (!root)
        return 0;

    int lheight = inOrderTraversal(root->left);
    int rheight = inOrderTraversal(root->right);
    int current = std::max(lheight, rheight) + 1;
    return current;
}

int Solution(const Node* root)
{
    return inOrderTraversal(root);
}

void test() {
    Node node1({ 1, nullptr, nullptr });
    Node node2({ 4, nullptr, nullptr });
    Node node3({ 3, nullptr, nullptr });
    Node node4({ 8, nullptr, nullptr });
    Node node5({ 5, &node3, &node4 });
    assert(Solution(&node5) == 2);
}
