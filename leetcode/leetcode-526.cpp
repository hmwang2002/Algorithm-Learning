#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countArrangement(int n)
    {
        vector<int> memo(1 << n, -1);
        function<int(int)> dfs = [&](int s) -> int
        {
            if (s == 0)
                return 1;
            int &res = memo[s];
            if (res != -1)
            {
                return res;
            }
            res = 0;
            int i = __builtin_popcount(s);
            for (int j = 1; j <= n; j++)
            {
                if (s >> (j - 1) & 1 && (i % j == 0 || j % i == 0))
                {
                    res += dfs(s ^ (1 << (j - 1)));
                }
            }
            return res;
        };
        return dfs((1 << n) - 1);
    }
};