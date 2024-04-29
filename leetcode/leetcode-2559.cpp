#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int check(string &s)
    {
        int n = s.size();
        return (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') && (s[n - 1] == 'a' || s[n - 1] == 'e' || s[n - 1] == 'i' || s[n - 1] == 'o' || s[n - 1] == 'u');
    }

    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        int n = words.size();
        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + check(words[i]);
        }
        vector<int> res;
        for (int i = 0; i < queries.size(); i++)
        {
            res.push_back(pre[queries[i][1] + 1] - pre[queries[i][0]]);
        }
        return res;
    }
};