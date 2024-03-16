#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ans;
        int n = nums.size();
        int min_Diff = INT32_MAX;
        for (int i = 0; i < n - 2; i++)
        {
            int x = nums[i];
            if (i > 0 && x == nums[i - 1])
                continue;
            int s = x + nums[i + 1] + nums[i + 2];
            if (s > target)
            {
                if (s - target < min_Diff)
                {
                    ans = s;
                }
                break;
            }

            s = x + nums[n - 2] + nums[n - 1];
            if (s < target)
            {
                if (target - s < min_Diff)
                {
                    ans = s;
                    min_Diff = target - s;
                }
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                s = x + nums[j] + nums[k];
                if (s == target)
                {
                    return target;
                }
                if (s > target)
                {
                    if (s - target < min_Diff)
                    {
                        ans = s;
                        min_Diff = s - target;
                    }
                    k--;
                }
                else if (s < target)
                {
                    if (target - s < min_Diff)
                    {
                        ans = s;
                        min_Diff = target - s;
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};