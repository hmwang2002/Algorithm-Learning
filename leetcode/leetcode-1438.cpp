#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        // 使用红黑树辅助
        multiset<int> s;
        int n = nums.size();
        int l = 0, r = 0;
        int res = 0;
        while (r < n)
        {
            s.insert(nums[r]);
            while (*s.rbegin() - *s.begin() > limit)
            {
                s.erase(s.find(nums[l++]));
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        // 单调队列辅助
        deque<int> queMax, queMin;
        int n = nums.size();
        int res = 0;
        for (int l = 0, r = 0; r < n; r++)
        {
            while (!queMax.empty() && queMax.back() < nums[r])
            {
                queMax.pop_back();
            }
            while (!queMin.empty() && queMin.back() > nums[r])
            {
                queMin.pop_back();
            }
            queMax.push_back(nums[r]), queMin.push_back(nums[r]);
            while (!queMax.empty() && !queMin.empty() && queMax.front() - queMin.front() > limit)
            {
                if (nums[l] == queMin.front())
                    queMin.pop_front();
                if (nums[l] == queMax.front())
                    queMax.pop_front();
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};