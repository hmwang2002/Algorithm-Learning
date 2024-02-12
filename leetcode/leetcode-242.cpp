#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if(s.size() != t.size())
            return false;
        vector<int> table(26, 0);
        for(char a : s) {
            table[a - 'a']++;
        }
        for(char b : t) {
            table[b - 'a']--;
            if(table[b - 'a'] < 0)
                return false;
        }
        return true;
    }
};