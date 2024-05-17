#include <bits/stdc++.h>

using namespace std;

auto _{
    []() noexcept
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr), std::cout.tie(nullptr);
        return 0;
    }()};

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int cnt = 0;
        long long res = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp[nums[i]] == 0)
                cnt++;
            else if (mp[nums[i]] == 1)
                cnt--;
            mp[nums[i]]++;
            sum += nums[i];
            if (i >= k)
            {
                mp[nums[i - k]]--;
                sum -= nums[i - k];
                if (mp[nums[i - k]] == 1)
                    cnt++;
                else if (mp[nums[i - k]] == 0)
                    cnt--;
            }
            if (i >= k - 1 && cnt == k)
            {
                res = max(res, sum);
            }
        }
        return res;
    }
};