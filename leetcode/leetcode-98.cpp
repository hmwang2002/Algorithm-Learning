#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    // 官解的这个效率还不如我自己写的，但是简洁确实简洁
    // bool helper(TreeNode *root, long lower, long upper)
    // {
    //     if (root == nullptr)
    //         return true;
    //     if (root->val <= lower || root->val >= upper)
    //         return false;
    //     return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    // }

    // bool isValidBST(TreeNode *root)
    // {
    //     return helper(root, LONG_MIN, LONG_MAX);
    // }

    // bool isValidBST(TreeNode *root)
    // {
    //     if (root == nullptr)
    //         return true;
    //     if (isValidBST(root->left) && isValidBST(root->right))
    //     {
    //         TreeNode *l = root->left, *r = root->right;
    //         if (!l && !r)
    //             return true;
    //         else if (!l)
    //         {
    //             while (r->left != nullptr)
    //             {
    //                 r = r->left;
    //             }
    //             if (r->val > root->val)
    //                 return true;
    //         }
    //         else if (!r)
    //         {
    //             while (l->right != nullptr)
    //             {
    //                 l = l->right;
    //             }
    //             if (l->val < root->val)
    //                 return true;
    //         }
    //         else
    //         {
    //             while (r->left != nullptr)
    //             {
    //                 r = r->left;
    //             }
    //             while (l->right != nullptr)
    //             {
    //                 l = l->right;
    //             }
    //             if (l->val < root->val && r->val > root->val)
    //                 return true;
    //         }
    //     }
    //     return false;
    // }

    bool isValidBST(TreeNode *root)
    {
        if(!root)
            return true;
        stack<TreeNode *> stk;
        stk.push(root);
        TreeNode *prev = nullptr;
        while(!stk.empty()) {
            TreeNode *node = stk.top();
            if(node) {
                stk.pop();
                if(node->right) {
                    stk.push(node->right);
                }
                stk.push(node);
                stk.push(nullptr);
                if(node->left)
                    stk.push(node->left);
            } else {
                stk.pop();
                node = stk.top();
                stk.pop();
                if(prev && prev->val >= node->val) {
                    return false;
                }
                prev = node;
            }
        }
        return true;
    }
};