#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lower_bound(vector<int> &nums, int target)
    {
        int left = 0, right = (int)nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }

    int maximumCount(vector<int> &nums)
    {
        int pos = lower_bound(nums, 1);
        int neg = lower_bound(nums, 0);
        int n1 = nums.size() - pos, n2 = neg;
        return max(n1, n2);
    }
};