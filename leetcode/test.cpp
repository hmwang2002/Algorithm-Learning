#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> dq;
        vector<int> res(n - k + 1);
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            while (!dq.empty() && i - k + 1 > dq.front())
            {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
            {
                res[j++] = nums[dq.front()];
            }
        }
        return res;
    }
};