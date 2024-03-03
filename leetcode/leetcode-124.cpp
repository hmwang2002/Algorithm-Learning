#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    int maxSum = INT_MIN;

    int maxGain(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        int curSum = node->val + leftGain + rightGain;
        maxSum = max(curSum, maxSum);

        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode *root)
    {
        maxGain(root);
        return maxSum;
    }
};