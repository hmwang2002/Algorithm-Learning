#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int ans = 0, l = 0, r = n - 1, pre_max = 0, suf_max = 0;
        while (l < r)
        {
            pre_max = max(pre_max, height[l]);
            suf_max = max(suf_max, height[r]);
            ans += pre_max < suf_max ? pre_max - height[l++] : suf_max - height[r--];
        }
        return ans;
    }
};