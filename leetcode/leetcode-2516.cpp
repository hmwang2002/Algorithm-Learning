#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        vector<int> cnt(3);
        int n = s.size();
        if (n < 3 * k)
            return -1;
        for (char c : s)
        {
            cnt[c - 'a']++;
        }
        int a = cnt[0] - k, b = cnt[1] - k, c = cnt[2] - k;
        if (a == 0 && b == 0 && c == 0)
            return n;
        if (a < 0 || b < 0 || c < 0)
            return -1;
        int res = 0;
        cnt = vector<int>(3);
        for (int l = 0, r = 0; r < n; r++)
        {
            cnt[s[r] - 'a']++;
            while (cnt[0] > a || cnt[1] > b || cnt[2] > c)
            {
                cnt[s[l++] - 'a']--;
            }
            res = max(res, r - l + 1);
        }
        return n - res;
    }
};