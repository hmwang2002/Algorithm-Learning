#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool check(vector<int> &cnt, int len, string &s)
    {
        int n = s.size();
        for (int i = 0; i < n; i += len)
        {
            vector<int> tmp(26);
            for (int j = i; j < i + len; j++)
                tmp[s[j] - 'a']++;
            for (int j = 0; j < 26; j++)
            {
                if (tmp[j] * (n / len) != cnt[j])
                    return false;
            }
        }
        return true;
    }

    int minAnagramLength(string s)
    {
        int n = s.size();
        vector<int> cnt(26);
        for (char c : s)
        {
            cnt[c - 'a']++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0 && check(cnt, i, s))
            {
                return i;
            }
        }
        return n;
    }
};