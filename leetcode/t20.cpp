#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        vector<string> rows(numRows);
        int r = 0, flag = -1;
        for (int i = 0; i < s.size(); i++)
        {
            rows[r].push_back(s[i]);
            if (r == 0 || r == numRows - 1)
            {
                flag = -flag;
            }
            r += flag;
        }
        string res;
        for (auto &row : rows)
        {
            res += row;
        }
        return res;
    }
};