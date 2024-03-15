﻿/*struct Node {
  int value;
  const Node* left = nullptr;
  const Node* right = nullptr;
};*/

#include "solution_tree.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

std::vector<std::string> inOrderTraversal(const Node* root)
{
    if (!root->left && !root->right)
        return { std::to_string(root->value) };


    auto lStr = root->left ? inOrderTraversal(root->left) : std::vector<std::string>{};
    auto rStr = root->right ? inOrderTraversal(root->right) : std::vector<std::string>{};
    lStr.insert(lStr.end(), rStr.begin(), rStr.end());
    for (auto& v : lStr)
        v = std::to_string(root->value) + v;

    return lStr;
}

int Solution(const Node* root)
{
    auto vec = inOrderTraversal(root);
    int sum = 0;
    for (auto& v : vec)
        sum += std::stoi(v);

    return sum;
}


void test() {
    Node node1({ 2, nullptr, nullptr });
    Node node2({ 1, nullptr, nullptr });
    Node node3({ 3, &node1, &node2 });
    Node node4({ 2, nullptr, nullptr });
    Node node5({ 1, nullptr, &node3 });
    assert(Solution(&node5) == 275);
}
