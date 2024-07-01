#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> cnt;
        for (char c : magazine)
        {
            cnt[c]++;
        }
        for (char c : ransomNote)
        {
            cnt[c]--;
            if (cnt[c] < 0)
                return false;
        }
        return true;
    }
};