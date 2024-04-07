#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return {-1, -1};
        vector<int> res(2);
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (nums[l] != target)
            return {-1, -1};
        res[0] = l;
        r = l + 1;
        while (r < nums.size())
        {
            if (nums[r] == target)
                r++;
            else
                break;
        }
        res[1] = r - 1;
        return res;
    }
};