#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int balancedString(string s)
    {
        int n = s.size(), m = n / 4;
        unordered_map<char, int> cnt;
        for (char c : s)
        {
            cnt[c]++;
        }
        if (cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m)
            return 0;
        int ans = n, l = 0;
        for (int r = 0; r < n; r++)
        {
            --cnt[s[r]];
            while (cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m)
            {
                ans = min(ans, r - l + 1);
                ++cnt[s[l++]];
            }
        }
        return ans;
    }
};