#include <bits/stdc++.h>

using namespace std;

// 算两次太慢了
class Solution
{
public:
    int atMostKDistinct(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int res = 0;
        for (int l = 0, r = 0; r < nums.size(); r++)
        {
            mp[nums[r]]++;
            while (mp.size() > k)
            {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
            res += r - l + 1;
        }
        return res;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
};

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> num1(n + 1), num2(n + 1);
        int tot1 = 0, tot2 = 0;
        int l1 = 0, l2 = 0, r = 0;
        int ret = 0;
        while (r < n)
        {
            if (!num1[nums[r]])
            {
                tot1++;
            }
            num1[nums[r]]++;
            if (!num2[nums[r]])
            {
                tot2++;
            }
            num2[nums[r]]++;
            while (tot1 > k)
            {
                num1[nums[l1]]--;
                if (!num1[nums[l1]])
                {
                    tot1--;
                }
                l1++;
            }
            while (tot2 > k - 1)
            {
                num2[nums[l2]]--;
                if (!num2[nums[l2]])
                {
                    tot2--;
                }
                l2++;
            }
            ret += l2 - l1;
            r++;
        }
        return ret;
    }
};