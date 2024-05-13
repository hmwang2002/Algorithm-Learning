#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int divisorSubstrings(int num, int k)
    {
        int cnt = 0, cur = 0;
        int copy = num;
        long long div = pow(10, k);

        cur = num % div;
        num /= div;

        div /= 10;
        if (cur != 0 && copy % cur == 0)
            cnt++;
        while (num > 0)
        {
            cur /= 10;
            cur += (num % 10) * div;
            num /= 10;
            if (cur != 0 && copy % cur == 0)
                cnt++;
        }
        return cnt;
    }
};