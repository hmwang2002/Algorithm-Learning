#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int maxLen = 0;
        int l = 0;
        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
            while (mp[s[i]] > 1)
            {
                mp[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, i - l + 1);
        }
        return maxLen;
    }
};