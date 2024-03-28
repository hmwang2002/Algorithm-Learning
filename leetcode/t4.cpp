#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    unordered_map<int, int> inorderIndex;
    vector<int> pre;

    TreeNode *helper(int root, int inLeft, int inRight)
    {
        if (inLeft > inRight)
            return nullptr;
        int val = pre[root];
        int index = inorderIndex[val];
        TreeNode *node = new TreeNode(val);
        node->left = helper(root + 1, inLeft, index - 1);
        node->right = helper(root + index - inLeft + 1, index + 1, inRight);
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

int main()
{
    vector<int> preorder = {3,
                            9,
                            20,
                            15,
                            7};
    vector<int> inorder = {9,
                           3,
                           15,
                           20,
                           7};
    Solution s;
    TreeNode *root = s.buildTree(preorder, inorder);
}