#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int duplicateInArray(vector<int> &nums)
    {
        int l = 1, r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r) >> 1;
            int s = 0;
            for(auto x : nums)
                s += (x >= l && x <= mid);
            if (s > mid - l + 1)
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};