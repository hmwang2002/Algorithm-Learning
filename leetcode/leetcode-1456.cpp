#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k)
    {
        int maxAns = 0, cur = 0;
        for (int i = 0; i < k; i++)
        {
            cur += isVowel(s[i]);
        }
        maxAns = cur;
        for (int i = k; i < s.size(); i++)
        {
            cur = cur + isVowel(s[i]) - isVowel(s[i - k]);
            maxAns = max(maxAns, cur);
        }
        return maxAns;
    }
};