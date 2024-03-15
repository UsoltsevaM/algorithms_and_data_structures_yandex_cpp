﻿#include "solution_tree.h"
#include <cassert>
#include <stack>

/*
struct Node {
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
};
*/

using namespace std;

bool inOrderTraversal(const Node* curNode, const Node* root, std::stack<int>& st, bool push)
{
    if (!curNode)
        return true;

    if (!inOrderTraversal(curNode->left, root, st, push))
        return false;

    if (curNode == root)
        push = false;
    else
    {
        if (push)
            st.push(curNode->value);
        else
        {
            if (st.empty())
                return false;

            if (curNode->value == st.top())
                st.pop();
        }
    }

    if (!inOrderTraversal(curNode->right, root, st, push))
        return false;

    return true;
}

bool Solution(const Node* root)
{
    std::stack<int> st;
    bool push = true;
    if (!inOrderTraversal(root, root, st, push))
        return false;

    return st.empty();
}

void test() {
    Node node2({ 1, nullptr, nullptr });
    Node node1({ 1, nullptr, nullptr });
    Node node0({ 1, &node1, &node2 });

    assert(Solution(&node0));
}
