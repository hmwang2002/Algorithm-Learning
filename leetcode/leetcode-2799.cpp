#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int m = unordered_set<int>(nums.begin(), nums.end()).size();
        unordered_map<int, int> cnt;
        int l = 0, res = 0;
        for (int r = 0; r < n; r++)
        {
            cnt[nums[r]]++;
            while (cnt.size() == m)
            {
                res += n - r;
                cnt[nums[l]]--;
                if (cnt[nums[l]] == 0)
                {
                    cnt.erase(nums[l]);
                }
                l++;
            }
        }
        return res;
    }
};