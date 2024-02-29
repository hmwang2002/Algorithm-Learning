#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

// class Solution
// {
//     unordered_map<int, int> index;

// public:
//     TreeNode *myBuildTree(vector<int> &preorder, vector<int> &inorder, int preLeft, int preRight, int inLeft, int inRight)
//     {
//         if (preLeft > preRight)
//             return nullptr;
//         int rootNum = preorder[preLeft];
//         // 在中序遍历中的位置
//         int inorderIndex = index[rootNum];
//         // 先建立根节点
//         TreeNode *root = new TreeNode(rootNum);
//         int leftTreeSize = inorderIndex - inLeft;
//         root->left = myBuildTree(preorder, inorder, preLeft + 1, preLeft + leftTreeSize, inLeft, inorderIndex - 1);
//         root->right = myBuildTree(preorder, inorder, preLeft + leftTreeSize + 1, preRight, inorderIndex + 1, inRight);
//         return root;
//     }

//     // 递归, O(n), O(n)
//     TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
//     {
//         int n = preorder.size();
//         for (int i = 0; i < n; i++)
//         {
//             index[inorder[i]] = i;
//         }
//         return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
//     }
// };

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (!preorder.size())
            return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode *> stk;
        stk.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); i++)
        {
            int preOrderVal = preorder[i];
            TreeNode *node = stk.top();
            if (node->val != inorder[inorderIndex])
            {
                node->left = new TreeNode(preOrderVal);
                stk.push(node->left);
            }
            else
            {
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex])
                {
                    node = stk.top();
                    stk.pop();
                    inorderIndex++;
                }
                node->right = new TreeNode(preOrderVal);
                stk.push(node->right);
            }
        }
        return root;
    }
};