#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int res = 0, n = s.size();
        vector<int> cnt(26, 0);
        for (auto &c : s)
            cnt[c - 'a']++;
        for (int i = 0; i < n; i++)
        {
            while (i < n && cnt[s[i] - 'a'] < k)
                i++;
            int start = i, len = 0;
            while (i < n && cnt[s[i] - 'a'] >= k)
            {
                i++;
                len++;
            }
            if (start == 0 && len == n)
                return n;
            if (len >= k)
            {
                res = max(res, longestSubstring(s.substr(start, len), k));
            }
        }
        return res;
    }
};