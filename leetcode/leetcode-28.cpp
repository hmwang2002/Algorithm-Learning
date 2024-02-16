#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (haystack.size() < needle.size())
            return -1;
        for (int i = 0; i <= haystack.size() - needle.size(); i++)
        {
            if (haystack[i] == needle[0])
            {
                string s = haystack.substr(i, needle.size());
                if (s == needle)
                {
                    return i;
                }
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