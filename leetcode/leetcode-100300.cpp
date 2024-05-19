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
    long long sumDigitDifferences(vector<int> &nums)
    {
        int n = nums.size();
        int N = to_string(nums[0]).size();
        vector<vector<int>> cnt(N, vector<int>(10, 0));
        for (int num : nums)
        {
            int k = 0;
            while (num > 0)
            {
                cnt[k++][num % 10]++;
                num /= 10;
            }
        }
        long long res = 0;
        for (int i = 0; i < N; i++)
        {
            long long s = 0;
            for (int j = 0; j < 10; j++)
            {
                s += cnt[i][j] * (n - cnt[i][j]);
            }
            res += s;
        }
        return res / 2;
    }
};