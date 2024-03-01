#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
    unordered_map<int, int> index;
    int post_idx;

public:
    TreeNode *myBuildTree(vector<int> &inorder, vector<int> &postorder, int inorder_left, int inorder_right)
    {
        if (inorder_left > inorder_right)
            return nullptr;
        int rootNum = postorder[post_idx];
        post_idx--;
        int inorderIndex = index[rootNum];
        TreeNode *root = new TreeNode(rootNum);
        // 后序优先右子树
        root->right = myBuildTree(inorder, postorder, inorderIndex + 1, inorder_right);
        root->left = myBuildTree(inorder, postorder, inorder_left, inorderIndex - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = (int)postorder.size();
        post_idx = n - 1;
        for (int i = 0; i < n; i++)
        {
            index[inorder[i]] = i;
        }
        return myBuildTree(inorder, postorder, 0, n - 1);
    }
};