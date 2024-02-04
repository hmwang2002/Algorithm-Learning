#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int cnt[26] = {0};
        for (int i = 0; i < magazine.size(); i++) {
            cnt[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            cnt[ransomNote[i] - 'a']--;
            if(cnt[ransomNote[i] - 'a'] < 0)
                return false;
        }
        return true;
    }
};