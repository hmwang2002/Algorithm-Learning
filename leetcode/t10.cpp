#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &val)
    {
        int first = val[0], second = max(val[0], val[1]);
        for (int i = 2; i < val.size(); i++)
        {
            int temp = second;
            second = max(second, first + val[i]);
            first = temp;
        }
        return second;
    }

    int deleteAndEarn(vector<int> &nums)
    {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> val(maxVal + 1);
        for (int &num : nums)
        {
            val[num] += num;
        }
        return rob(val);
    }
};