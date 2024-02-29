#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return n;
        int pre = 1;
        int cur = 2;
        for (int i = 3; i <= n; i++)
        {
            int sum = pre + cur;
            pre = cur;
            cur = sum;
        }
        return cur;
    }
};