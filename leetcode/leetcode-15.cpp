#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int r = n - 1;
            int target = -nums[i];
            for (int l = i + 1; l < n - 1; l++)
            {
                if (l > i + 1 && nums[l] == nums[l - 1])
                {
                    continue;
                }
                while (l < r)
                {
                    if (nums[l] + nums[r] == target)
                    {
                        ans.push_back({nums[i], nums[l], nums[r]});
                        break;
                    }
                    else if (nums[l] + nums[r] > target)
                    {
                        r--;
                    } else {
                        break;
                    }
                }
                if(l == r) break;
            }
        }

        return ans;
    }
};