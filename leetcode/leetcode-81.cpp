#include <bits/stdc++.h>

using namespace std;

// class Solution
// {
// public:
//     bool search(vector<int> &nums, int target)
//     {
//         int n = nums.size();
//         if (n == 0)
//             return false;
//         if (n == 1)
//         {
//             return nums[0] == target;
//         }
//         int l = 0, r = n - 1;
//         while (l <= r)
//         {
//             int mid = (l + r) >> 1;
//             if (nums[mid] == target)
//                 return true;
//             if (nums[l] == nums[mid] && nums[r] == nums[mid])
//             {
//                 l++;
//                 r--;
//             }
//             else if (nums[mid] <= nums[r])
//             {
//                 if (nums[l] <= target && nums[mid] > target)
//                 {
//                     r = mid - 1;
//                 }
//                 else
//                 {
//                     l = mid + 1;
//                 }
//             }
//             else
//             {
//                 if (nums[mid] < target && target <= nums[n - 1])
//                 {
//                     l = mid + 1;
//                 }
//                 else
//                 {
//                     r = mid - 1;
//                 }
//             }
//         }
//         return false;
//     }
// };

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
                return true;

            if (nums[mid] > nums[start])
            {
                if (nums[mid] > target && target >= nums[start])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else if (nums[mid] < nums[start])
            {
                if (nums[mid] < target && target <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            else
            {
                ++start;
            }
        }
        return false;
    }
};