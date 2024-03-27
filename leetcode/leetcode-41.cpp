#include <bits/stdc++.h>

using namespace std;

// class Solution
// {
// public:
//     int firstMissingPositive(vector<int> &nums)
//     {
//         int n = nums.size();
//         for (int &a : nums)
//         {
//             if (a <= 0)
//             {
//                 a = n + 1;
//             }
//         }

//         for (int i = 0; i < n; i++)
//         {
//             int num = abs(nums[i]);
//             if (num <= n)
//             {
//                 nums[num - 1] = -abs(nums[num - 1]);
//             }
//         }
//         for (int i = 0; i < n; i++)
//         {
//             if (nums[i] > 0)
//             {
//                 return i + 1;
//             }
//         }
//         return n + 1;
//     }
// };

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};