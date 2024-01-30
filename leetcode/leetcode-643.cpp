#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        vector<int> s;
        s.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
            s.push_back(nums[i] + s[i - 1]);
        double res = s[k - 1] * 1.0 / k;
        for (int i = 0; i < s.size() - k; i++)
        {
            res = max(res, (s[i + k] - s[i]) * 1.0 / k);
        }
        return res;
    }
};