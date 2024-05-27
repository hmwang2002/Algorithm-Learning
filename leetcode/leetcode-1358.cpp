#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        vector<int> cnt(3);
        int l = 0, res = 0, n = s.size();
        for (int r = 0; r < n; r++)
        {
            cnt[s[r] - 'a']++;
            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0)
            {
                cnt[s[l++] - 'a']--;
                res += n - r;
            }
        }
        return res;
    }
};