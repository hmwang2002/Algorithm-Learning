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

class Solution
{
public:
    int myAtoi(string s)
    {
        int res = 0;
        bool flag = true;
        int index = 0;
        while (s[index] == ' ')
        {
            index++;
        }
        bool c = false;
        for (int i = index; i < s.size(); i++)
        {
            if (s[i] == '+' && !c)
            {
                c = true;
                continue;
            }
            else if (s[i] == '-' && !c)
            {
                c = true;
                flag = false;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                c = true;
                int tmp = s[i] - '0';
                if (flag && (res > 214748364 || (res == 214748364 && tmp >= 7)))
                {
                    return INT_MAX;
                }
                else if (!flag && (res > 214748364 || (res == 214748364 && tmp >= 8)))
                {
                    return INT_MIN;
                }
                res = res * 10 + tmp;
            }
            else
            {
                break;
            }
        }
        return flag ? res : -res;
    }
};