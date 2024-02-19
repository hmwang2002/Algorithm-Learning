#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // int strStr(string haystack, string needle)
    // {
    //     if (haystack.size() < needle.size())
    //         return -1;
    //     for (int i = 0; i <= haystack.size() - needle.size(); i++)
    //     {
    //         if (haystack[i] == needle[0])
    //         {
    //             string s = haystack.substr(i, needle.size());
    //             if (s == needle)
    //             {
    //                 return i;
    //             }
    //         }
    //     }
    //     return -1;
    // }

    // kmp
    int strStr(string haystack, string needle)
    {
        int n = haystack.size(), m = needle.size();
        if (m == 0)
            return 0;
        vector<int> p(m); // next数组
        for (int i = 1, j = 0; i < m; i++)
        {
            while (j > 0 && needle[i] != needle[j])
            {
                j = p[j - 1];
            }
            if (needle[i] == needle[j])
            {
                j++;
            }
            p[i] = j;
        }
        for (int i = 0, j = 0; i < n; i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = p[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == m)
            {
                return i - m + 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution *s = new Solution();
    int ans = s->strStr("aaa", "aaaa");
    cout << ans << endl;
}