#include <bits/stdc++.h>

using namespace std;

// class Solution
// {
// public:
//     const static int mod = 1e9 + 7;

//     int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
//     {
//         vector<int> cp = nums1;
//         sort(cp.begin(), cp.end());
//         int replace_index = -1, replace = -1, cur = 0;
//         for (int i = 0; i < nums1.size(); i++)
//         {
//             if (nums1[i] == nums2[i])
//                 continue;
//             int x = nums2[i];
//             int diff = abs(nums1[i] - nums2[i]);

//             int l = upper_bound(cp.begin(), cp.end(), x) - cp.begin() - 1;
//             if (l >= 0 && x - cp[l] < diff && diff - (x - cp[l]) > cur)
//             {
//                 cur = diff - (x - cp[l]);
//                 replace_index = i;
//                 replace = cp[l];
//             }
//             int r = lower_bound(cp.begin(), cp.end(), x) - cp.begin();
//             if (r < cp.size() && cp[r] - x < diff && diff - (cp[r] - x) > cur)
//             {
//                 cur = diff - (cp[r] - x);
//                 replace_index = i;
//                 replace = cp[r];
//             }
//         }
//         if (replace_index != -1)
//         {
//             nums1[replace_index] = replace;
//         }
//         int res = 0;
//         for (int i = 0; i < nums1.size(); i++)
//         {
//             res = (res + abs(nums1[i] - nums2[i])) % mod;
//         }
//         return res;
//     }
// };

class Solution
{
public:
    static constexpr int mod = 1e9 + 7;

    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> rec(nums1);
        sort(rec.begin(), rec.end());
        int sum = 0, maxn = 0;
        int n = nums1.size();
        for (int i = 0; i < n; i++)
        {
            int diff = abs(nums1[i] - nums2[i]);
            sum = (sum + diff) % mod;
            int j = lower_bound(rec.begin(), rec.end(), nums2[i]) - rec.begin();
            if (j < n)
            {
                maxn = max(maxn, diff - (rec[j] - nums2[i]));
            }
            if (j > 0)
            {
                maxn = max(maxn, diff - (nums2[i] - rec[j - 1]));
            }
        }
        return (sum - maxn + mod) % mod;
    }
};

              int
              main()
{
    vector<int> nums1 = {1, 10, 4, 4, 2, 7};
    vector<int> nums2 = {9, 3, 5, 1, 7, 4};
    Solution s;
    int ans = s.minAbsoluteSumDiff(nums1, nums2);
    cout << ans << endl;
}