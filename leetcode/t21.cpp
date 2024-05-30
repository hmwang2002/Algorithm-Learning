#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

/*
LMax1是nums1左边部分的最大值
RMin1是nums1右边部分的最小值
LMax2是nums2左边部分的最大值
RMin2是nums2右边部分的最小值
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
        int LMax1, LMax2, RMin1, RMin2, lo = 0, hi = 2 * n;
        while (lo <= hi)
        {
            int c1 = (lo + hi) / 2;
            int c2 = m + n - c1;

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
            {
                break;
            }
        }
        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
    }
};