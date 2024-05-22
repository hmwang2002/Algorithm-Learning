#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int ans = 0, cnt = 0;
        for (int l = 0, r = 0; r < nums.size(); r++)
        {
            if (!nums[r])
                cnt++;
            while (cnt > k)
            {
                cnt -= nums[l++] == 0;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};