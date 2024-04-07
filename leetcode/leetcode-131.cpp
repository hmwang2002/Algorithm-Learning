#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> res;
    vector<string> path;

    void backtrace(string &s, int index)
    {
        if (index == s.length())
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.length(); i++)
        {
            string sub = s.substr(index, i - index + 1);
            int l = 0, r = sub.size() - 1;
            bool flag = true;
            while (l < r)
            {
                if (sub[l] != sub[r])
                {
                    flag = false;
                    break;
                }
                l++;
                r--;
            }
            if (flag)
            {
                path.push_back(sub);
                backtrace(s, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        backtrace(s, 0);
        return res;
    }
};