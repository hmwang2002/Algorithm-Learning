#include <bits/stdc++.h>

using namespace std;

class Solution
{
    /*
     * s中有多少个子串，其每个字符恰好出现k次
     * 枚举子串有多少种字母 m
     * 长度恰好为m * k的窗口内，是否满足每个字符恰好出现k次
     */
    int f(string_view s, int k)
    {
        int res = 0;
        for (int m = 1; m <= 26 && k * m <= s.length(); m++)
        {
            int cnt[26]{};
            auto check = [&]()
            {
                for (int i = 0; i < 26; i++)
                {
                    if (cnt[i] && cnt[i] != k)
                    {
                        return;
                    }
                }
                res++;
            };
            for (int right = 0; right < s.length(); right++)
            {
                cnt[s[right] - 'a']++;
                int left = right + 1 - k * m;
                if (left >= 0)
                {
                    check();
                    cnt[s[left] - 'a']--;
                }
            }
        }
        return res;
    }

public:
    int countCompleteSubstrings(string word, int k)
    {
        int n = word.size(), ans = 0;
        string_view s(word);
        // 对于第二个情况，我们分割字符串为若干满足条件2的块
        for (int i = 0; i < n;)
        {
            int st = i;
            for (i++; i < n && abs(int(word[i]) - int(word[i - 1])) <= 2; i++)
                ;
            ans += f(s.substr(st, i - st), k);
        }
        return ans;
    }
};