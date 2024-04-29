#include <bits/stdc++.h>

using namespace std;

class NumArray
{
public:
    vector<int> pre;

    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        pre.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        return pre[right + 1] - pre[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */