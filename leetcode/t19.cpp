#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

auto _{
    []() noexcept
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr), std::cout.tie(nullptr);
        return 0;
    }()};

class Solution
{
public:
    int cnt = 0;

    void dfs(TreeNode *root, long cur, int targetSum, unordered_map<long, int> &prefix)
    {
        if (root == nullptr)
            return;
        cur += root->val;
        cnt += prefix[cur - targetSum];
        prefix[cur] += 1;
        dfs(root->left, cur, targetSum, prefix);
        dfs(root->right, cur, targetSum, prefix);
        prefix[cur] -= 1;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return 0;
        unordered_map<long, int> prefix;
        prefix[0l] = 1;
        dfs(root, 0, targetSum, prefix);
        return cnt;
    }
};