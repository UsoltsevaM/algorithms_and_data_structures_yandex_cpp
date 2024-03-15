﻿/*struct Node {
  Node* left;
  Node* right;
  int value;
};*/


#include "solution.h"
#include <cassert>

Node* insert(Node* root, Node* curNode, int key)
{
    if (!root)
    {
        root = new Node{ nullptr, nullptr, key };
        return root;
    }

    if (key >= curNode->value)
    {
        if (!curNode->right)
        {
            curNode->right = new Node{ nullptr, nullptr, key };
            return root;
        }
        insert(root, curNode->right, key);
    }
    else
    {
        if (!curNode->left)
        {
            curNode->left = new Node{ nullptr, nullptr, key };
            return root;
        }
        insert(root, curNode->left, key);
    }
    return root;

}

Node* insert(Node* root, int key)
{
    return insert(root, root, key);
}

void test() {
    Node node1({ nullptr, nullptr, 7 });
    Node node2({ &node1, nullptr, 8 });
    Node node3({ nullptr, &node2, 7 });
    Node* newHead = insert(&node3, 6);
    assert(newHead->left->value == 6);
    assert(newHead == &node3);
}
