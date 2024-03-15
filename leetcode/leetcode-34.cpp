#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return {-1, -1};
        int l = 0, r = nums.size() - 1;
        vector<int> res;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        if (nums[l] != target)
            return {-1, -1};
        res.push_back(l);
        while (l + 1 < nums.size())
        {
            if (nums[l + 1] == target)
            {
                l++;
            }
            else
            {
                res.push_back(l);
                break;
            }
        }
        if(res.size() == 1)
            res.push_back(l);
        return res;
    }
};