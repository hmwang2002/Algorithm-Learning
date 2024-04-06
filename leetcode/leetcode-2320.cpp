#include <bits/stdc++.h>

using namespace std;

const static int MOD = 1e9 + 7, MX = 10001;
int f[MX];

int init = []()
{
    f[0] = 1, f[1] = 2;
    for (int i = 2; i < MX; i++)
    {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    }
    return 0;
}();

class Solution
{
public:
    int countHousePlacements(int n)
    {
        return (long)f[n] * f[n] % MOD;
    }
};