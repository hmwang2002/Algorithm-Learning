#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        int ans = -1;
        vector<int> max_val(10, INT_MIN);
        for (int v : nums)
        {
            int max_d = 0;
            for (int x = v; x; x /= 10)
            {
                max_d = max(max_d, x % 10);
            }
            ans = max(ans, v + max_val[max_d]);
            max_val[max_d] = max(max_val[max_d], v);
        }
        return ans;
    }
};