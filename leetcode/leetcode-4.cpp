#include <bits/stdc++.h>
using namespace std;

// class Solution {
//     int getKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
//         int len1 = end1 - start1 + 1;
//         int len2 = end2 - start2 + 1;
//         // 让len1的长度小于len2，这样就能保证如果有数组空了，一定是nums1
//         if(len1 > len2) return getKth(nums2, start2, end2, nums1, start1, end1, k);
//         if(len1 == 0) return nums2[start2 + k - 1];

//         if(k == 1) return min(nums1[start1], nums2[start2]);

//         int i = start1 + min(len1, k / 2) - 1;
//         int j = start2 + min(len2, k / 2) - 1;

//         if ( nums1[i] > nums2[j]) return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
//         else return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
//     }
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size(), m = nums2.size();
//         int left = (m + n + 1) / 2, right = (m + n + 2) / 2;
//         return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) + getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) / 2.0;
//     }
// };

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int i = 0, j = 0;
//         int len1 = nums1.size(), len2 = nums2.size();
//         vector<int> res;
//         while (i < len1 && j < len2) {
//             if (nums1[i] <= nums2[j]) {
//                 res.push_back(nums1[i++]);
//             } else {
//                 res.push_back(nums2[j++]);
//             }
//         }
//         while(i < len1) {
//             res.push_back(nums1[i++]);
//         }
//         while(j < len2) {
//             res.push_back(nums2[j++]);
//         }
//         if ((len1 + len2) % 2 == 0) return (res[(len1 + len2) / 2] + res[(len1 + len2) / 2 - 1]) / 2.0;
//         else return res[(len1 + len2) / 2];
//     }
// };

/*
https://leetcode.cn/problems/median-of-two-sorted-arrays/solutions/6098/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu
*/
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        if (n > m)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n; // 我们目前是虚拟加了'#'所以数组1是2*n + 1的长度
        while (lo <= hi)
        {
            c1 = (lo + hi) / 2;
            c2 = m + n - c1;

            LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
            LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

            if (LMax1 > RMin2)
            {
                hi = c1 - 1;
            }
            else if (LMax2 > RMin1)
            {
                lo = c1 + 1;
            }
            else
                break;
        }
        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
    }
};