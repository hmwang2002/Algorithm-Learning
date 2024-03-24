#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    void inorder(vector<int> &nums, TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(nums, root->left);
        nums.push_back(root->val);
        inorder(nums, root->right);
    }

    pair<int, int> findTwoSwapped(vector<int> &nums)
    {
        int index1 = -1, index2 = -1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                index2 = i + 1;
                if (index1 == -1)
                {
                    index1 = i;
                } else {
                    break;
                }
            }
        }
        return {nums[index1], nums[index2]};
    }

    void reverse(TreeNode *root, int count, int n, int m)
    {
        if (root != nullptr)
        {
            if (root->val == n || root->val == m)
            {
                root->val = root->val == n ? m : n;
                if (--count == 0)
                {
                    return;
                }
            }
            reverse(root->left, count, n, m);
            reverse(root->right, count, n, m);
        }
    }

    void recoverTree(TreeNode *root)
    {
        vector<int> nums;
        inorder(nums, root);
        pair<int, int> p = findTwoSwapped(nums);
        reverse(root, 2, p.first, p.second);
    }
};