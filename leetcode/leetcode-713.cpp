#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;
        int ans = 0, prod = 1, left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            prod *= nums[right];
            while (prod >= k)
            {
                prod /= nums[left++];
            }
            ans += right - left + 1;
        }
        return ans;
    }
};