#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
    int ans = 0;

public:
    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int l = height(root->left), r = height(root->right);
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        height(root);
        return ans;
    }
};