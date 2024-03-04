#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class BSTIterator
{
    TreeNode *it;
    stack<TreeNode *> stk;

public:
    BSTIterator(TreeNode *root) : it(root)
    {
    }

    int next()
    {
        while (it != nullptr)
        {
            stk.push(it);
            it = it->left;
        }
        it = stk.top();
        stk.pop();
        int ret = it->val;
        it = it->right;
        return ret;
    }

    bool hasNext()
    {
        return it != nullptr || !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */