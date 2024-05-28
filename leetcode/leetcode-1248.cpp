#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0, res = 0;
        for (int &x : nums)
        {
            if (x % 2 == 1)
                cnt++;
            mp[cnt]++;
            res += mp[cnt - k];
        }
        return res;
    }
};

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> cnt(n + 1);
        int odd = 0, ans = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; i++)
        {
            odd += nums[i] & 1;
            ans += odd >= k ? cnt[odd - k] : 0;
            cnt[odd] += 1;
        }
        return ans;
    }
};