#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    double quickMul(double x, long n)
    {
        if (n == 1)
        {
            return x;
        }
        if (n % 2)
        {
            return quickMul(x * x, n / 2) * x;
        }
        return quickMul(x * x, n / 2);
    }

    double myPow(double x, int n)
    {
        if (n == 0)
            return 1.0;
        return n > 0 ? quickMul(x, n) : 1 / quickMul(x, -(long)n);
    }
};