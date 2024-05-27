#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int mx = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int cnt = 0, l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            cnt += nums[r] == mx;
            while (cnt == k)
            {
                cnt -= nums[l] == mx;
                l++;
            }
            ans += l;
        }
        return ans;
    }
};