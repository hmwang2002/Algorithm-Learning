#include <bits/stdc++.h>

using namespace std;

class Solution
{
    static const int N = 2005;
    int mem[N][N];

    int dfs(vector<int> &nums, int l, int r, int point)
    {
        if (l >= r)
        {
            return 1; // 最差也有1
        }
        if (mem[l][r] != -1)
            return mem[l][r];
        int res = 1;
        if (nums[l] + nums[l + 1] == point)
        {
            res = max(res, dfs(nums, l + 2, r, point) + 1);
        }
        if (nums[r] + nums[r - 1] == point)
        {
            res = max(res, dfs(nums, l, r - 2, point) + 1);
        }
        if (nums[l] + nums[r] == point)
        {
            res = max(res, dfs(nums, l + 1, r - 1, point) + 1);
        }
        mem[l][r] = res;
        return res;
    }

public:
    int maxOperations(vector<int> &nums)
    {
        // 记忆化搜索
        memset(mem, -1, sizeof mem);
        int l = 0, r = nums.size() - 1;
        return max(dfs(nums, l + 2, r, nums[l] + nums[l + 1]), max(dfs(nums, l + 1, r - 1, nums[l] + nums[r]), dfs(nums, l, r - 2, nums[r] + nums[r - 1])));
    }
};