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
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = 1;
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + (nums[i] % 2 != nums[i - 1] % 2);
        }
        vector<bool> res;
        for (auto &q : queries)
        {
            int start = q[0], end = q[1];
            if (end == start)
            {
                res.push_back(true);
                continue;
            }
            int cnt = prefix[end] - prefix[start];
            if (cnt == end - start)
            {
                res.push_back(true);
            }
            else
                res.push_back(false);
        }
        return res;
    }
};