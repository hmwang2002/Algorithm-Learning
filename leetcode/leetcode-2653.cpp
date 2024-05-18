#include <bits/stdc++.h>

using namespace std;

auto _{[]() noexcept
       {
           std::ios::sync_with_stdio(false);
           std::cin.tie(nullptr);
           std::cout.tie(nullptr);
           return 0;
       }()};

class Solution
{
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
    {
        const int BIAS = 50;
        int cnt[BIAS * 2 + 1] = {0};
        int n = nums.size();
        for (int i = 0; i < k - 1; i++)
        {
            ++cnt[nums[i] + BIAS];
        }
        vector<int> ans(n - k + 1);
        for (int i = k - 1; i < n; i++)
        {
            ++cnt[nums[i] + BIAS];
            int left = x;
            for (int j = 0; j < BIAS; j++)
            {
                left -= cnt[j];
                if (left <= 0)
                { // 找到美丽值
                    ans[i - k + 1] = j - BIAS;
                    break;
                }
            }
            --cnt[nums[i - k + 1] + BIAS];
        }
        return ans;
    }
};