#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long continuousSubarrays(vector<int> &nums)
    {
        long long ans = 0;
        multiset<int> s;
        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            s.insert(nums[r]);
            while (*s.rbegin() - *s.begin() > 2)
            {
                s.erase(s.find(nums[l++]));
            }
            ans += r - l + 1;
        }
        return ans;
    }
};

class Solution
{
public:
    long long continuousSubarrays(vector<int> &nums)
    {
        long long ans = 0;
        map<int, int> cnt;
        int len = nums.size();
        for (int i = 0, j = 0; i < len; i++)
        {
            cnt[nums[i]]++;
            while (cnt.rbegin()->first - cnt.begin()->first > 2)
            {
                if (--cnt[nums[j]] == 0)
                    cnt.erase(nums[j]);
                j++;
            }
            ans += i - j + 1;
        }
        return ans;
    }
};