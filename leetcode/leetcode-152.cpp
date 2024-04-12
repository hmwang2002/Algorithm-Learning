#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxF = nums[0];
        int minF = nums[0];
        int ans = maxF;
        for (int i = 1; i < nums.size(); i++) {
            int temp = maxF;
            maxF = max(nums[i], max(maxF * nums[i], minF * nums[i]));
            minF = min(nums[i], min(minF * nums[i], temp * nums[i]));
            ans = max(ans, maxF);
        }
        return ans;
    }
};