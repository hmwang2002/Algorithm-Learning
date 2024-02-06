#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int ans = 0;
        bool flag = false;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (!false && s[i] != ' ')
            {
                flag = true;
            }
            else if (flag && s[i] == ' ')
            {
                break;
            }
            if (flag)
            {
                ans++;
            }
        }
        return ans;
    }
};