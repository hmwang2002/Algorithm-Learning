#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        int ans = INT32_MAX;
        int sum = 0;
        for (int start = 0, end = 0; end < n; end++)
        {
            sum += nums[end];
            while (sum >= target)
            {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
        }
        return ans == INT32_MAX ? 0 : ans;
    }
};