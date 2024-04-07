#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> prefix_function(string s)
    {
        int n = s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++)
        {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j])
            {
                j = pi[j - 1];
            }
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }

    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();
        string curr = needle + "#" + haystack;
        vector<int> lps = prefix_function(curr);
        for (int i = n + 1; i <= m + n; i++)
        {
            if (lps[i] == n)
                return i - 2 * n;
        }
        return -1;
    }
};