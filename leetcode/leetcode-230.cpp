#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    //用栈的和递归差不多，感觉自己写的递归上不去运行时间纯粹力扣测评机器的问题
    // int kthSmallest(TreeNode *root, int k)
    // {
    //     int ans = 0;
    //     stack<TreeNode *> stk;
    //     while (root != nullptr || stk.size() > 0)
    //     {
    //         while (root != nullptr)
    //         {
    //             stk.push(root);
    //             root = root->left;
    //         }

    //         root = stk.top();
    //         stk.pop();
    //         k--;
    //         if (k == 0)
    //         {
    //             ans = root->val;
    //             break;
    //         }
    //         root = root->right;
    //     }
    //     return ans;
    // }

    int cnt = 0;
    int ans;
    void traversal(TreeNode *root, int k)
    {
        if (root == nullptr)
            return;
        traversal(root->left, k);
        cnt++;
        if (cnt == k)
        {
            ans = root->val;
            return;
        }
        traversal(root->right, k);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        traversal(root, k);
        return ans;
    }
};