#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
                if (i == n - 1)
                {
                    res.push_back(node->val);
                }
            }
        }
        return res;
    }
};