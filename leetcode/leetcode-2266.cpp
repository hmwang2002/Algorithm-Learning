#include <bits/stdc++.h>

using namespace std;

const static int MOD = 1e9 + 7, MX = 1e5 + 1;
int f[MX], g[MX];
int init = []()
{
    f[0] = g[0] = 1;
    f[1] = g[1] = 1;
    f[2] = g[2] = 2;
    f[3] = g[3] = 4;
    for (int i = 4; i < MX; i++)
    {
        f[i] = (int)(((long)f[i - 1] + f[i - 2] + f[i - 3]) % MOD);
        g[i] = (int)(((long)g[i - 1] + g[i - 2] + g[i - 3] + g[i - 4]) % MOD);
    }
    return 0;
}();

class Solution
{
public:
    int countTexts(string s)
    {
        int ans = 1, cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            ++cnt;
            char c = s[i];
            if(i == s.length() - 1 || c != s[i + 1]) {
                ans = (int)((long)ans * (c != '7' && c != '9' ? f[cnt] : g[cnt]) % MOD);
                cnt = 0;
            }
        }
        return ans;
    }
};