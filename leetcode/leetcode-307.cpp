#include <bits/stdc++.h>

using namespace std;

class NumArray
{
    vector<int> nums;
    vector<int> tree;

    int prefixSum(int i)
    {
        int s = 0;
        for (; i > 0; i &= i - 1)
        {
            s += tree[i];
        }
        return s;
    }

public:
    NumArray(vector<int> &nums) : nums(nums.size()), tree(nums.size() + 1)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            update(i, nums[i]);
        }
    }

    void update(int index, int val)
    {
        // delta为新的值与原来的值的差
        int delta = val - nums[index];
        nums[index] = val;
        for (int i = index + 1; i < tree.size(); i += i & -i)
        {
            tree[i] += delta;
        }
    }

    int sumRange(int left, int right)
    {
        return prefixSum(right + 1) - prefixSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

class NumArray
{
    vector<int> nums;
    vector<int> tree;

    int prefixSum(int i)
    {
        int s = 0;
        for (; i > 0; i &= i - 1)
        {
            s += tree[i];
        }
        return s;
    }

public:
    // O(n)的写法
    NumArray(vector<int> &nums) : nums(nums), tree(nums.size() + 1)
    {
        for (int i = 1; i <= nums.size(); i++)
        {
            tree[i] += nums[i - 1];
            int nxt = i + (i & -i); // 下一个关键区间的右端点
            if (nxt <= nums.size())
            {
                tree[nxt] += tree[i];
            }
        }
    }

    void update(int index, int val)
    {
        // delta为新的值与原来的值的差
        int delta = val - nums[index];
        nums[index] = val;
        for (int i = index + 1; i < tree.size(); i += i & -i)
        {
            tree[i] += delta;
        }
    }

    int sumRange(int left, int right)
    {
        return prefixSum(right + 1) - prefixSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */