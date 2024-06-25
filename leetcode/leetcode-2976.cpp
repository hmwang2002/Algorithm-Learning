#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        vector<vector<int>> f(26, vector<int>(26, 0x3f3f3f3f));
        for (int i = 0; i < original.size(); i++)
        {
            int x = original[i] - 'a', y = changed[i] - 'a', w = cost[i];
            if (f[x][y] != 0x3f3f3f3f)
            {
                f[x][y] = min(f[x][y], w);
            }
            else
                f[x][y] = w;
        }

        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < source.size(); i++)
        {
            int x = source[i] - 'a', y = target[i] - 'a';
            if (x != y)
            {
                if (f[x][y] == 0x3f3f3f3f)
                    return -1;
                ans += (long long)f[x][y];
            }
        }
        return ans;
    }
};