#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    const static int MOD = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> powers;
        while (n)
        {
            // 找出n的最低有效位
            int lowbit = n & (-n);
            powers.push_back(lowbit);
            n ^= lowbit;
        }
        int m = powers.size();
        int res[m][m];
        for (int i = 0; i < m; i++)
        {
            res[i][i] = powers[i];
            for (int j = i + 1; j < m; j++)
            {
                res[i][j] = 1ll * res[i][j - 1] * powers[j] % MOD;
            }
        }
        vector<int> ans;
        for (auto &q : queries)
        {
            int l = q[0], r = q[1];
            ans.push_back(res[l][r]);
        }
        return ans;
    }
};