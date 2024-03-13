#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();

        auto get = [&](int i) -> pair<int, int>
        {
            if (i == -1 || i == n)
                return {0, 0};
            return {1, nums[i]};
        };

        int l = 0, r = n - 1, ans = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (get(mid - 1) < get(mid) && get(mid) > get(mid + 1))
            {
                ans = mid;
                break;
            }
            if (get(mid) < get(mid + 1))
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};