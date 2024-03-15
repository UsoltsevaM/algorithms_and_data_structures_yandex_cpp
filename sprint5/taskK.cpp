﻿/*struct Node {
  Node* left;
  Node* right;
  int value;
};*/

#include "solution.h"
#include <iostream>

using namespace std;


void print_range(Node* root, int l, int r)
{
    if (root)
    {
        print_range(root->left, l, r);
        if (root->value >= l && root->value <= r)
            std::cout << root->value << " ";
        print_range(root->right, l, r);
    }
}

void test() {
    Node node1({ nullptr, nullptr, 2 });
    Node node2({ nullptr, &node1, 1 });
    Node node3({ nullptr, nullptr, 8 });
    Node node4({ nullptr, &node3, 8 });
    Node node5({ &node4, nullptr, 9 });
    Node node6({ &node5, nullptr, 10 });
    Node node7({ &node2, &node6, 5 });
    print_range(&node7, 2, 8);
    // expected output: 2 5 8 8
}
