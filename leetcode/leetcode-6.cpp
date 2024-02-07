#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        vector<string> rows(numRows);
        int i = 0, flag = -1;
        for (char c : s)
        {
            rows[i].push_back(c);
            if (i == 0 || i == numRows - 1)
            {
                flag = -flag;
            }
            i += flag;
        }
        string res;
        for (string &s1 : rows)
        {
            res += s1;
        }
        return res;
    }
};