#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int target = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int cur = nums[l] + nums[r];
                if (cur == target)
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    do
                    {
                        l++;
                    } while (l < r && nums[l] == nums[l - 1]);
                }
                else if (cur < target)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return res;
    }
};