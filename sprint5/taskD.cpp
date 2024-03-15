﻿/*
struct Node {
  int value;
  const Node* left = nullptr;
  const Node* right = nullptr;
};*/


#include "solution_tree.h"
#include <cassert>

using namespace std;

bool compareTrees(const Node* root1, const Node* root2)
{
    if (!root1 && !root2)
        return true;

    if (root1 && !root2 || root2 && !root1)
        return false;

    if (root1->value != root2->value)
        return false;

    if (!compareTrees(root1->left, root2->left))
        return false;

    if (!compareTrees(root1->right, root2->right))
        return false;

    return true;
}

bool Solution(const Node* root1, const Node* root2) {
    return  compareTrees(root1, root2);
}

void test() {

    Node node1({ 1, nullptr, nullptr });
    Node node2({ 2, nullptr, nullptr });
    Node node3({ 3, &node1, &node2 });

    Node node4({ 1, nullptr, nullptr });
    Node node5({ 2, nullptr, nullptr });
    Node node6({ 3, &node4, &node5 });
    assert(Solution(&node3, &node6));
}
