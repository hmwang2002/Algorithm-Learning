#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string lastNonEmptyString(string s)
    {
        int n = s.length();
        vector<int> vec(26, 0);
        for (char c : s)
        {
            vec[c - 'a']++;
        }
        int m = *max_element(vec.begin(), vec.end());
        string ans;
        for (int i = n - 1; i >= 0; i--)
        {
            // 倒序保证是最后删除的字符
            if (vec[s[i] - 'a'] == m)
            {
                ans += s[i];
                vec[s[i] - 'a']--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};