#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

// 在两个函数中一个专门深搜，一个负责从新的节点遍历，可以去重，全放在一个函数中会有重复结果
// class Solution
// {
// public:
//     int cnt = 0;

//     void dfs(TreeNode *root, long target)
//     {
//         if (!root)
//         {
//             return;
//         }
//         if (root->val == target)
//         {
//             cnt++;
//         }
//         dfs(root->left, target - root->val);
//         dfs(root->right, target - root->val);
//     }

//     int pathSum(TreeNode *root, int targetSum)
//     {
//         if (root == nullptr)
//         {
//             return 0;
//         }
//         dfs(root, targetSum);
//         pathSum(root->left, targetSum);
//         pathSum(root->right, targetSum);
//         return cnt;
//     }
// };

// 前缀和 + 回溯
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
        {
            return 0;
        }
        unordered_map<long, int> prefix;
        prefix.emplace(0l, 1);
        dfs(root, 0, targetSum, prefix);
        return cnt;
    }
};