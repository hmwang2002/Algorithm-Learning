#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    int ans = INT32_MAX;
    int pre = -1;

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        if (pre == -1)
        {
            pre = root->val;
        }
        else
        {
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        dfs(root->right);
    }

    int getMinimumDifference(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};