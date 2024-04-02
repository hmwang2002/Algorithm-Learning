#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    int maxSum = INT_MIN;

    int maxGain(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int l = max(maxGain(root->left), 0);
        int r = max(maxGain(root->right), 0);
        maxSum = max(maxSum, l + r + root->val);
        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode *root)
    {
        maxGain(root);
        return maxSum;
    }
};