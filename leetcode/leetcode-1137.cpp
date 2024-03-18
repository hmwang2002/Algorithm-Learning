#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n <= 1)
            return n;
        int t0 = 0, t1 = 1, t2 = 1;
        int t3;
        for (int i = 3; i <= n; i++)
        {
            t3 = t0 + t1 + t2;
            t0 = t1, t1 = t2, t2 = t3;
        }
        return t2;
    }
};