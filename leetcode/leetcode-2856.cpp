#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minLengthAfterRemovals(vector<int> &nums)
    {
        int n = nums.size();
        int mid = nums[n / 2];
        int k = upper_bound(nums.begin(), nums.end(), mid) - lower_bound(nums.begin(), nums.end(), mid);
        return max(k * 2 - n, n % 2);
    }
};