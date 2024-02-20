#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int min_begin = 0, min_len = 0;
        unordered_map<char, int> mp;
        for (char c : t)
        {
            mp[c]++;
        }
        int m = s.length(), n = t.length();
        for (int left = 0, right = 0; right < m; right++)
        {
            if (mp[s[right]] > 0)
            {
                n--;
            }
            mp[s[right]]--;
            if (n == 0)
            {
                while (mp[s[left]] < 0) // 缩小范围
                {
                    mp[s[left]]++;
                    left++;
                }
                int len = right - left + 1;
                if (min_len == 0 || min_len > len)
                {
                    min_len = len;
                    min_begin = left;
                }
                mp[s[left++]]++; // 破坏条件
                n++;
            }
        }
        return s.substr(min_begin, min_len);
    }
};