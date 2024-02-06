#include <bits/stdc++.h>

using namespace std;

class Solution
{
    unordered_set<int> mset;

public:
    bool isHappy(int n)
    {
        while(1) {
            if(n == 1)
                return true;
            if(mset.find(n) != mset.end())
                return false;
            mset.insert(n);
            string s = to_string(n);
            n = 0;
            for (int i = 0; i < s.size(); i++) {
                n += (s[i] - '0') * (s[i] - '0');
            }
        }
        return false;
    }
};