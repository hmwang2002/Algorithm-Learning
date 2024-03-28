#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> res;

    bool isValid(string &s, int start, int end)
    {
        if (start > end)
            return false;
        if (s[start] == '0' && start != end)
            return false;
        int num = 0;
        for (int i = start; i <= end; i++)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                return false;
            }
            num = num * 10 + s[i] - '0';
            if (num > 255)
            {
                return false;
            }
        }
        return true;
    }

    void backtrace(string &s, int start, int cnt)
    {
        if (cnt == 3)
        {
            if (isValid(s, start, s.size() - 1))
            {
                res.push_back(s);
            }
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            if (isValid(s, start, i))
            {
                s.insert(s.begin() + i + 1, '.');
                cnt++;
                backtrace(s, i + 2, cnt);
                cnt--;
                s.erase(s.begin() + i + 1);
            }
            else
            {
                break;
            }
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        if (s.size() < 4 || s.size() > 12)
            return res;
        backtrace(s, 0, 0);
        return res;
    }
};