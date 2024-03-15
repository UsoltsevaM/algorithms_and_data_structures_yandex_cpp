﻿/*struct Node {
  int value;
  const Node* left = nullptr;
  const Node* right = nullptr;
};*/


#include "solution_tree.h"
#include <cassert>
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

int findMaxPath(const Node* root, int& maxPathSumOverall)
{
    if (!root)
        return 0;

    int leftMaxSum = findMaxPath(root->left, maxPathSumOverall);
    int rightMaxSum = findMaxPath(root->right, maxPathSumOverall);

    int maxLeftRightMiddle = std::max(std::max(leftMaxSum, rightMaxSum) + root->value, root->value);

    maxPathSumOverall = std::max(std::max(leftMaxSum + rightMaxSum + root->value, maxLeftRightMiddle), maxPathSumOverall);

    return maxLeftRightMiddle;
}

int Solution(const Node* root)
{
    int maxPathSum = std::numeric_limits<int>::min();
    findMaxPath(root, maxPathSum);
    return maxPathSum;
}

void test() {
    Node node1({ 5, nullptr, nullptr });
    Node node2({ 1, nullptr, nullptr });
    Node node3({ -3, &node2, &node1 });
    Node node4({ 2, nullptr, nullptr });
    Node node5({ 2, &node4, &node3 });
    assert(Solution(&node5) == 6);
}
