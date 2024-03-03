#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *cur = root;
        while (cur != nullptr)
        {
            if (cur->left != nullptr)
            {
                TreeNode *next = cur->left;
                TreeNode *predecessor = next;
                while (predecessor->right != nullptr)
                {
                    predecessor = predecessor->right;
                }
                predecessor->right = cur->right;
                cur->left = nullptr;
                cur->right = next;
            }
            cur = cur->right;
        }
    }
};