#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int l = 0, r = 0;
        while(l < s.size()) {
            if( r == t.size())
                return false;
            if(s[l] == t[r]) {
                l++;
            }
            r++;
        }
        return true;
    }
};