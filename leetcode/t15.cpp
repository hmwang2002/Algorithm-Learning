#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        int sum = nums[0], maxSum = nums[0], minSum = nums[0], maxCur = nums[0], minCur = nums[0];
        for (int i = 1; i < n; i++) {
            sum += nums[i];
            maxCur = max(nums[i], maxCur + nums[i]);
            maxSum = max(maxSum, maxCur);
            minCur = min(nums[i], minCur + nums[i]);
            minSum = min(minSum, minCur);
        }
        if(maxSum < 0) {
            return maxSum;
        }
        return max(maxSum, sum - minSum);
    }
};