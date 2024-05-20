#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isArraySpecial(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return true;
        for (int i = 0; i < n - 1; i++)
        {
            // 注意位运算优先级低，所以要加括号
            if ((nums[i] & 1) == (nums[i + 1] & 1))
                return false;
        }
        return true;
    }
};