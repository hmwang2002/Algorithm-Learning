#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return dfs(root, targetSum, 0);
    }

    bool dfs(TreeNode *root, int target, int sum)
    {
        if (root == nullptr)
            return false;
        sum += root->val;
        if (sum == target && root->left == nullptr && root->right == nullptr)
            return true;
        return dfs(root->left, target, sum) || dfs(root->right, target, sum);
    }
};