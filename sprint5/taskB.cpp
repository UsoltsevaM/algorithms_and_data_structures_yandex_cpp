﻿#include "solution_tree.h"
#include <cassert>
#include <algorithm>

using namespace std;


const int INF = -1e9;

int isBalanced(const Node* root, int h)
{
    if (root == nullptr)
        return h - 1;

    int h1 = isBalanced(root->left, h + 1);
    int h2 = isBalanced(root->right, h + 1);
    if (std::abs(h1 - h2) > 1)
        return INF;

    return std::max(h1, h2);
}

bool Solution(const Node* root)
{
    return isBalanced(root, 0) != INF;
}

void test() {
    Node node1({ 1, nullptr, nullptr });
    Node node2({ -5, nullptr, nullptr });
    Node node3({ 3, &node1, &node2 });
    Node node4({ 10, nullptr, nullptr });
    Node node5({ 2, &node3, &node4 });
    auto res = Solution(&node5);
    assert(Solution(&node5));
}
