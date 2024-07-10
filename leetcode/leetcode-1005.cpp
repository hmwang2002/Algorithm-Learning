#include <bits/stdc++.h>

using namespace std;

// class Solution
// {
// public:
//     int largestSumAfterKNegations(vector<int> &nums, int k)
//     {
//         sort(nums.begin(), nums.end());
//         int index = 0;
//         bool flag = true;
//         while (k--)
//         {
//             if (index >= nums.size() || nums[index] >= 0)
//             {
//                 flag = false;
//                 sort(nums.begin(), nums.end());
//                 index = 0;
//             }
//             nums[index] = -nums[index];
//             if (flag)
//                 index++;
//         }
//         return accumulate(nums.begin(), nums.end(), 0);
//     }
// };

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (int num : nums)
        {
            freq[num]++;
        }
        int ans = accumulate(nums.begin(), nums.end(), 0);
        for (int i = -100; i < 0; i++)
        {
            if (freq[i])
            {
                int ops = min(k, freq[i]);
                ans += (-i) * ops * 2;
                freq[i] -= ops;
                freq[-i] += ops;
                k -= ops;
                if (k == 0)
                    break;
            }
        }
        if (k > 0 && k % 2 == 1 && !freq[0])
        {
            for (int i = 1; i <= 100; i++)
            {
                if (freq[i])
                {
                    ans -= i * 2;
                    break;
                }
            }
        }
        return ans;
    }
};