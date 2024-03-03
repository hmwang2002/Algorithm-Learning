#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int leftDepth = 0, rightDepth = 0;
        while (left)
        {
            leftDepth++;
            left = left->left;
        }
        while (right)
        {
            rightDepth++;
            right = right->right;
        }
        if (leftDepth == rightDepth)
        {
            return (2 << leftDepth) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};