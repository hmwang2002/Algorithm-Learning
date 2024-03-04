#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

// class Solution
// {
//     unordered_map<int, TreeNode *> fa;
//     unordered_map<int, bool> vis;

// public:
//     void dfs(TreeNode *root)
//     {
//         if (root == nullptr)
//             return;
//         if (root->left)
//         {
//             fa[root->left->val] = root;
//             dfs(root->left);
//         }
//         if (root->right)
//         {
//             fa[root->right->val] = root;
//             dfs(root->right);
//         }
//     }
//     TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
//     {
//         fa[root->val] = nullptr;
//         dfs(root);
//         while (p != nullptr)
//         {
//             vis[p->val] = true;
//             p = fa[p->val];
//         }
//         while (q != nullptr)
//         {
//             if (vis[q->val])
//                 return q;
//             q = fa[q->val];
//         }
//         return nullptr;
//     }
// };

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || p == root || q == root)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
        {
            return root;
        }
        else if (left && !right)
        {
            return left;
        }
        else if (!left && right)
        {
            return right;
        }

        return nullptr;
    }
};