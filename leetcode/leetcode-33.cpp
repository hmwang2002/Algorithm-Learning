#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < nums[r])
            {
                if (nums[mid] < target && target < nums[r])
                {
                    l = mid + 1;
                }
                else if (target == nums[r])
                {
                    return r;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else
            {
                if (nums[l] < target && nums[mid] > target)
                {
                    r = mid - 1;
                } else if(nums[l] == target) {
                    return l;
                } else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};