#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int bestRotation(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> diffs(n);
        for (int i = 0; i < n; i++)
        {
            int low = (i + 1) % n;
            int high = (i + n - nums[i]) % n;
            diffs[low]++;
            if (high < n - 1)
                diffs[high + 1]--;
            if (low > high)
                diffs[0]++;
        }
        int max = diffs[0];
        int maxIndex = 0;
        for (int i = 1; i < n; i++)
        {
            diffs[i] += diffs[i - 1];
            if(max < diffs[i]) {
                max = diffs[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
};