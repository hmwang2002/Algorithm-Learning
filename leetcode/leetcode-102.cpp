#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> vec;
        if (root == nullptr)
            return vec;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> level;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            vec.push_back(level);
        }
        return vec;
    }
};