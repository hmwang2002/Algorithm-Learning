#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findRepeatDocument(vector<int> &documents)
    {
        unordered_map<int, bool> mp;
        for (int n : documents)
        {
            if (mp[n])
                return n;
            mp[n] = true;
        }
        return -1;
    }
};