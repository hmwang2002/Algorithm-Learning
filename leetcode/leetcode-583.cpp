#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minDistance(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<int> f(m + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0, pre = 0; j < m; j++)
            {
                int tmp = f[j + 1];
                f[j + 1] = s[i] == t[j] ? pre + 1 : max(f[j + 1], f[j]);
                pre = tmp;
            }
        }
        return n + m - 2 * f[m];
    }
};