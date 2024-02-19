#include <bits/stdc++.h>

using namespace std;

class Solution
{
    bool isPrefixAndSuffix(string &str1, string &str2)
    {
        if (str1.size() > str2.size())
            return false;
        int len1 = str1.size(), len2 = str2.size();
        string prefix = str2.substr(0, len1), suffix = str2.substr(len2 - len1, len1);
        return str1 == prefix && str1 == suffix;
    }

public:
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int n = words.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isPrefixAndSuffix(words[i], words[j]))
                    cnt++;
            }
        }
        return cnt;
    }
};