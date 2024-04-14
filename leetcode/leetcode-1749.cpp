#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0, p1 = 0, p2 = 0;
        for (int i = 0; i < n; i++)
        {
            p1 = max(p1 + nums[i], nums[i]);
            p2 = min(p2 + nums[i], nums[i]);
            ans = max(ans, max(abs(p1), abs(p2)));
        }
        return ans;
    }
};