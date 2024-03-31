#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root == nullptr || root == p || root == q)
            return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if(l == nullptr && r == nullptr)
            return nullptr;
        else if(l == nullptr)
            return r;
        else if(r == nullptr)
            return l;
        return root;
    }
};