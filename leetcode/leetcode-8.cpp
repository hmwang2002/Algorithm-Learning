#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        while (s[i] == ' ')
        {
            i++;
        }
        bool flag = true;
        if (s[i] == '-')
        {
            flag = false;
            i++;
        }
        else if (s[i] == '+')
        {
            i++;
        }
        int res = 0;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9')
        {
            int tmp = s[i] - '0';
            if (res > 214748364 || (res == 214748364 && tmp > 7))
            {
                if (flag)
                {
                    res = INT32_MAX;
                }
                else
                {
                    res = INT32_MIN;
                }
                break;
            }
            res = res * 10 + tmp;
            i++;
        }
        if (!flag && res != INT32_MIN)
            res = -res;
        return res;
    }
};