#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
    vector<int> pre;
    unordered_map<int, int> inorderIndex;

public:
    TreeNode *helper(int root, int l, int r)
    {
        if (l > r)
        {
            return nullptr;
        }
        int val = pre[root];
        TreeNode *node = new TreeNode(val);
        int inorder = inorderIndex[val];
        node->left = helper(root + 1, l, inorder - 1);
        node->right = helper(root + inorder - l + 1, inorder + 1, r);
        return node;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        pre = preorder;
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderIndex[inorder[i]] = i;
        }
        return helper(0, 0, inorder.size() - 1);
    }
};