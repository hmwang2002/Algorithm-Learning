#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    vector<int> res;

    void traversal(TreeNode *root) {
        if(root == nullptr) {
            return;
        }
        traversal(root->left);
        res.push_back(root->val);
        traversal(root->right);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        traversal(root);
        return res;
    }
};