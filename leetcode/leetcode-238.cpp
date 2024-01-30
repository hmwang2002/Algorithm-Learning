#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> res(len, 0);
        res[0] = 1;
        for (int i = 1; i < len; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int r = 1;
        for (int i = len - 2; i >= 0; i--) {
            r *= nums[i + 1];
            res[i] = res[i] * r;
        }
        return res;
    }
};