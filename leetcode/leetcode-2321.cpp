#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int solve(vector<int> &nums1, vector<int> &nums2)
    {
        int s1 = 0, s = 0, maxSum = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            s1 += nums1[i];
            s = max(s + nums2[i] - nums1[i], 0);
            maxSum = max(maxSum, s);
        }
        return s1 + maxSum;
    }

public:
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
    {
        return max(solve(nums1, nums2), solve(nums2, nums1));
    }
};