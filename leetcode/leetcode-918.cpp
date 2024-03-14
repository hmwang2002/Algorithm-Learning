#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int sum = nums[0];
        int maxSum = nums[0], maxCur = nums[0], minSum = nums[0], minCur = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            maxCur = max(nums[i], nums[i] + maxCur);
            maxSum = max(maxCur, maxSum);
            minCur = min(nums[i], nums[i] + minCur);
            minSum = min(minSum, minCur);
        }
        if(maxSum < 0)
            return maxSum;
        return max(maxSum, sum - minSum);
    }
};