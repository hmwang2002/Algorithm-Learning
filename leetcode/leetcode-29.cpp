#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
        {
            if (dividend == INT_MIN)
                return INT_MAX;
            else
                return -dividend;
        }
        long a = dividend, b = divisor;
        int sign = 1;
        if ((a > 0 && b < 0) || (a < 0 && b > 0))
        {
            sign = -1;
        }
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        long res = div(a, b);
        return sign == 1 ? res : -res;
    }

    long div(long a, long b)
    {
        if (a < b)
            return 0;
        long cnt = 1;
        long tb = b; // 在后面的代码中不更新b
        while ((tb + tb) <= a)
        {
            cnt = cnt + cnt; // 最小解翻倍
            tb = tb + tb;
        }
        return cnt + div(a - tb, b);
    }
};