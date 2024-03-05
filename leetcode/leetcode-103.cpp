#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        bool flag = true;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            deque<int> levelList;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (flag)
                {
                    levelList.push_back(node->val);
                }
                else
                {
                    levelList.push_front(node->val);
                }

                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            flag = !flag;
            res.emplace_back(vector<int>{levelList.begin(), levelList.end()});
        }
        return res;
    }
};