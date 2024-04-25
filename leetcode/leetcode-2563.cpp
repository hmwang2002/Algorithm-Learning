#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int l = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int r = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            ans += r - l;
        }
        return ans;
    }
};

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        int left = nums.size(), right = left;
        for (int j = 0; j < nums.size(); j++)
        {
            while (right && nums[right - 1] > upper - nums[j])
            {
                right--;
            }
            while (left && nums[left - 1] >= lower - nums[j])
            {
                left--;
            }
            ans += min(right, j) - min(left, j);
        }
        return ans;
    }
};